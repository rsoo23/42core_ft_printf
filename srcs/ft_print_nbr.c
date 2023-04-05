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

#include "ft_printf.h"

int     ft_numlen_int(int nb)
{
    int len;

    len = 0;
    if (nb == -2147483648)
        return (11);
    if (nb <= 0)
    {
        len++;
        nb = -nb;
    }
    while (nb > 0)
    {
        len++;
        nb /= 10;
    }
    return (len);
}

int     ft_putnbr_int(int nb)
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
        ft_putchar((nb % 10) + 48);
    }
    else
        ft_putchar(nb + 48);
    return (ft_numlen_int(nb));
}

int     ft_numlen_uint(unsigned int nb)
{
    int len;

    len = 0;
    if (nb == 0)
        return (1);
    while (nb > 0)
    {
        len++;
        nb /= 10;
    }
    return (len);
}

int     ft_putnbr_uint(unsigned int nb)
{
    if (nb > 9)
    {
        ft_putnbr_uint(nb / 10);
        ft_putchar((nb % 10) + 48);
    }
    else
        ft_putchar(nb + 48);
    return (ft_numlen_uint(nb));
}
