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

#include "../includes/ft_printf.h"

void	ft_putnbr_int_b(int nb, t_form *form)
{
	ft_numlen_int_b(nb, form);
	if (form->plus || (nb >= 0 && form->space))
		form->form_len++;
	if (form->minus != 0)
		ft_int_space_plus(nb, form);
	else if (form->plus)
	{
		ft_putchar('+');
		form->plus = 2;
	}
	ft_put_zero_space(form);
	if (form->minus == 0)
		ft_int_space_plus(nb, form);
}

void	ft_int_space_plus(int nb, t_form *form)
{
	if (nb >= 0 && form->space)
		ft_putchar(' ');
	else if (nb >= 0 && form->plus != 2 && form-> plus == 1)
		ft_putchar('+');
	if (form->prec_exist && form->form_len <= form->prec)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			form->prec++;
		}
		while (form->form_len < form->prec)
		{
			ft_putchar('0');
			form->form_len++;
		}
	}
	if ((long)nb == (long)2147483648)
		write(1, "2147483648", 11);
	else
		ft_putnbr_int(nb);
	return ;
}

void	ft_numlen_int_b(int nb, t_form *form)
{
	if (nb == -2147483648)
	{
		form->form_len += 11;
		return ;
	}
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

void	ft_putnbr_int(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_int(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr_int(nb / 10);
		ft_putnbr_int(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
