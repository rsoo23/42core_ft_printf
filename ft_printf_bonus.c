/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:01:26 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/02 21:01:26 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

// bonus
int		ft_printf(const char *s,...)
{
    va_list ap;
    int     len;
 
    len = 0;
	if (*s == '\0')
		return (ft_putstr("Error: empty string"));
    va_start(ap, s);
    while (*s)
    {
        if (*s != '%')
            len += ft_putchar(*s);
        else
            len += ft_parse_bonus(ap, s);
        if (*s != '\0') // deals with "%"
            s++;
    }
    va_end(ap);
    return (len);
}
