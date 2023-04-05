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
            len += ft_parse_bonus(ap, &s);
        s++;
    }
    va_end(ap);
    return (len);
}

int main(void)
{
    // %c
    // printf("%d\n", ft_printf("test: %c", 'z'));
    // printf("%d\n", printf("test: %10c", 'z'));

    // %p
    // char    c = 'b';
    // printf("%d\n", ft_printf("%-25p", &c));
    // printf("%d\n", printf("%-25p", &c));
    
    // %x and %X
    // printf("%d\n", ft_printf("%x", -123));
    // printf("%d\n", printf("%x", -123));
    // printf("%d\n", ft_printf("%#-15X", -2234));
    // printf("%d\n", printf("%#-15X", -2234));
    
    // %%
    // printf("%d\n", ft_printf("%%"));
    // printf("%d\n", printf("%%"));

    // %d or %i
    int num = -4;
    printf("%d\n", ft_printf("%10d", num));
    printf("%d\n", printf("%10d", num));

    // %u
    // printf("%d\n", ft_printf("%u", 4294967295));
    // printf("%d\n", printf("%u\n", 4294967295));
    
	// %s
    // printf("%d\n", printf("%s", "cheese"));
    // printf("%d\n", ft_printf("%s", "cheese"));




    // printf("%d\n", ft_printf("%p", 'a'));
    write(1, "\n", 1);
}