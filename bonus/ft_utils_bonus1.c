/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:22:33 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/04 16:22:33 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int		ft_valid_input(const char c, char *str)
{
	while (str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int     ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
