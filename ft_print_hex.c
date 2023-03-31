/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:17:01 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 20:17:01 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_hex_len(uintptr_t nb)
{
    int len;

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

int     ft_puthex(unsigned int nb, char format)
{
    if (nb >= 16)
        ft_puthex(nb / 16, format);
    if (format == 'x')
        ft_putchar("0123456789abcdef"[nb % 16]);
    else if (format == 'X')
        ft_putchar("0123456789ABCDEF"[nb % 16]);
    return (ft_hex_len(nb));
}