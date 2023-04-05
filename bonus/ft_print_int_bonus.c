/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/27 15:29:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void    ft_putnbr_int_b(int nb, t_form *form) // mfw - 0 + ' '
{
    ft_numlen_int_b(nb, form);
	if (form->minus)
		ft_int_space_plus(nb, form);
	while (form->form_len < form->min_fw)
    {
		if (form->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
        form->form_len++;
    }
    if (!(form->minus))
		ft_int_space_plus(nb, form);
}

void	ft_int_space_plus(int nb, t_form *form)
{
	if (nb >= 0 && form->space)
		form->form_len += ft_putchar(' ');
	else if (nb >= 0 && form->plus)
		form->form_len += ft_putchar('+');
	ft_putnbr_int(nb, form);
	return ;
}

void	ft_numlen_int_b(int nb, t_form *form)
{
    if (nb == -2147483648)
        form->form_len += 11;
    if (nb <= 0)
    {
        form->form_len++;
        nb = -nb;
    }
    while (nb > 0)
    {
        form->form_len++;
        nb /= 10;
    }
    return ;
}


void	ft_putnbr_int(int nb, t_form *form)
{
    if (nb == -2147483648)
	{
        write(1, "-2147483648", 11);
		form->form_len += 11;
	}
    else if (nb < 0)
    {
        ft_putchar('-');
		form->form_len++;
        ft_putnbr_int(-nb, form);
    }
    else if (nb > 9)
    {
        ft_putnbr_int(nb / 10, form);
        ft_putnbr_int(nb % 10, form);
    }
    else
	{
        ft_putchar(nb + 48);
		form->form_len++;
	}
}