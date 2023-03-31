/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:38 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 20:19:38 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putchar(char c)
{
    if (!c)
        return (0);
    write(1, &c, 1);
    return (1);
}

int     ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}


int		ft_put_percent(void)
{
    ft_putchar('%');
    return (1);
}