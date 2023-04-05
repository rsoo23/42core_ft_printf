/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:15:57 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 20:15:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_put_ptr_b(uintptr_t nb, t_form *form)
{
	form->form_len += 2 + ft_hex_len(nb);
	if (form->minus == 1)
		ft_put_ptr(nb);
	while (form->form_len < form->min_fw)
    {
		ft_putchar(' ');
        form->form_len++;
    }
    if (form->minus == 0)
		ft_put_ptr(nb);
}

int		ft_put_ptr(uintptr_t nb)
{
    if (nb == 0)
        return (ft_putstr("(nil)"));
    else
	{
    	ft_putstr("0x");
        ft_puthex_ptr(nb);
	}
	return (0);
}

void	ft_puthex_ptr(uintptr_t nb)
{
    if (nb >= 16)
        ft_puthex_ptr(nb / 16);
    ft_putchar("0123456789abcdef"[nb % 16]);
}