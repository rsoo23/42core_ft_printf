/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:25:19 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/03 14:25:19 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_puthex_b(unsigned int nb, t_form *form)
{
	if (form->hash)
		form->form_len += 2 + ft_hex_len(nb);
	else
		form->form_len += ft_hex_len(nb);
	if (form->minus)
		ft_puthex_hash(nb, form);
	else if (!(form->minus) && form->zero)
		ft_puthex_hash_zero(form);
	ft_put_zero_space(form);
	if (!(form->minus))
		ft_puthex_hash(nb, form);
}

void	ft_puthex_hash_zero(t_form *form)
{
	if (form->hash && form->spec == 'x')
		ft_putstr("0x");
	else if (form->hash && form->spec == 'X')
		ft_putstr("0X");
	form->zero = 2;
}

void	ft_puthex_hash(unsigned int nb, t_form *form)
{
	if (form->zero != 2)
	{
		if (form->hash && form->spec == 'x')
			ft_putstr("0x");
		else if (form->hash && form->spec == 'X')
			ft_putstr("0X");
	}
	ft_puthex(nb, form);
	return ;
}

void	ft_puthex(unsigned int nb, t_form *form)
{
	if (nb >= 16)
		ft_puthex(nb / 16, form);
	if (form->spec == 'x')
		ft_putchar("0123456789abcdef"[nb % 16]);
	else if (form->spec == 'X')
		ft_putchar("0123456789ABCDEF"[nb % 16]);
	return ;
}

int	ft_hex_len(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}
