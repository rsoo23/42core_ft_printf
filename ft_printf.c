/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:42 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/27 15:59:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *s,...)
{
    va_list ap;
    int     len;

    va_start(ap, s);
    len = 0;
    while (*s)
    {
        if (*s == '%')
        {
            s++;
            if (*s == 's' || *s == 'c' || *s == 37)
                len = ft_putstr(va_arg(ap, char*));
            // else if (*s == 'p')
            //     len = 
            else if (*s == 'd' || *s == 'i')
                len = ft_putnbr_int(va_arg(ap, int));
            else if (*s == 'u')
                len = ft_putnbr_uint(va_arg(ap, int));
            else if (*s == 'x')
                len = ft_puthex_low(va_arg(ap, int));
            else if (*s == 'X')
                len = ft_puthex_up(va_arg(ap, int));
        }
        s++;
    }
    va_end(ap);
    return (len);
}

int main()
{
    // char    str[] = "cHEESe";

    // %p
    // char    *ptr = str;
    // printf("%p\n", ptr);
    // int     outlen = ft_printf("%p", ptr);

    // %d or %i
    // int num = 4;
    // // printf("%d\n", ft_printf("%d", num));
    // printf("%d\n", printf("%d\n", num));

    // %u
    // unsigned int    num = 4294967295;
    // printf("%d\n", ft_printf("%u", num));
    // printf("%d\n", printf("%u\n", num));

    // %x and %X
    // int  num = -123;
    // printf("%d\n", ft_printf("%x", num));
    // printf("%d\n", printf("%x", num));
    // printf("%d\n", ft_printf("%X", num));
    // printf("%d\n", printf("%X", num));

    // %%
    // int     outlen = ft_printf("%%");

    // printf("%d", outlen);
}