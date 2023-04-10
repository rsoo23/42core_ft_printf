/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:29:29 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/05 23:29:29 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_uint_b(unsigned int nb, t_form *form)
{
	ft_numlen_uint_b(nb, form);
	if (form->minus)
		ft_putnbr_uint(nb, form);
	ft_put_zero_space(form);
	if (!(form->minus))
		ft_putnbr_uint(nb, form);
}

void	ft_numlen_uint_b(unsigned int nb, t_form *form)
{
	if (nb == 0)
		form->form_len++;
	while (nb > 0)
	{
		form->form_len++;
		nb /= 10;
	}
	return ;
}

void	ft_putnbr_uint(unsigned int nb, t_form *form)
{
	if (nb > 9)
		ft_putnbr_uint(nb / 10, form);
	ft_putchar("0123456789"[nb % 10]);
	return ;
}
