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

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t nb)
{
	if (nb == 0)
		return (ft_putstr("(nil)"));
	else
	{
		ft_putstr("0x");
		ft_puthex_ptr(nb);
	}
	return (ft_hex_len(nb) + 2);
}

void	ft_puthex_ptr(uintptr_t nb)
{
	if (nb >= 16)
		ft_puthex_ptr(nb / 16);
	ft_putchar("0123456789abcdef"[nb % 16]);
}
