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

// struct s_flag
// {
    
// }       t_flag


int ft_spec_parse(va_list ap, const char *s, int len)
{
    if (*s == 'c' || *s == 's')
        len = ft_putstr(va_arg(ap, char*));
    else if (*s == 'p')
        len = ft_put_ptr(va_arg(ap, uintptr_t));
    else if (*s == 'd' || *s == 'i')
        len = ft_putnbr_int(va_arg(ap, int));
    else if (*s == 'u')
        len = ft_putnbr_uint(va_arg(ap, unsigned int));
    else if (*s == 'x' || *s == 'X')
        len = ft_puthex(va_arg(ap, unsigned int), *s);
    else if (*s == '%')
        len = ft_put_percent();
    return (len);
}

int ft_printf(const char *s,...)
{
    va_list ap;
    int     len;

    len = 0;
    va_start(ap, s);
    while (*s)
    {
        if (*s == '%')
        {
            s++;
            len = ft_spec_parse(ap, s, len);
        }
        else
            ft_putchar(*s);
        s++;
    }
    va_end(ap);
    return (len);
}

int main(void)
{
    // %c
    // char    c = 'a';
    // printf("%d\n", ft_printf("%c", c));

    // %s
    // char    s[] = "cheese";
    // printf("%d\n", ft_printf("%s", s));

    // %p
    // char    c = 'b';
    // printf("%d\n", ft_printf("%p", NULL));
    // printf("%d\n", printf("%p", NULL));

    // %d or %i
    // int num = 4;
    // printf("%d\n", ft_printf("%d", num));
    // printf("%d\n", printf("%d\n", num));

    // %u
    // unsigned int    num = 4294967295;
    // printf("%d\n", ft_printf("%u", num));
    // printf("%d\n", printf("%u\n", num));

    // %x and %X
    // int  num = -2;
    // printf("%d\n", ft_printf("%x", num));
    // printf("%d\n", printf("%x", num));
    // printf("%d\n", ft_printf("%X", num));
    // printf("%d\n", printf("%X", num));

    // %%
    // printf("%d\n", ft_printf("%%"));
    // printf("%d\n", printf("%%"));

    printf("%d\n", printf("%5d", 1234));
}