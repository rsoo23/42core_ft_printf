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

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (*s == '\0')
		return (ft_putstr("Error: empty string"));
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			len += ft_putchar(*s);
		else
		{
			s++;
			if (ft_checkspec_all(s) == 1)
				len += ft_parse(ap, s, len);
		}
		if (*s != '\0')
			s++;
	}
	va_end(ap);
	return (len);
}

int	ft_parse(va_list ap, const char *s, int len)
{
	if (*s == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (*s == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (*s == 'p')
		len += ft_put_ptr(va_arg(ap, uintptr_t));
	else if (*s == 'd' || *s == 'i')
		len += ft_putnbr_int(va_arg(ap, int));
	else if (*s == 'u')
		len += ft_putnbr_uint(va_arg(ap, unsigned int));
	else if (*s == 'x' || *s == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), *s);
	else if (*s == '%')
		len += ft_putchar(va_arg(ap, int));
	return (len);
}

// int main(void)
// {
//     %c
//     printf("%d\n", ft_printf("%c", 'a'));

//     %s
//     printf("%d\n", ft_printf("%s", "cheese"));

//     %p
//     char    c = 'b';
//     printf("%d\n", ft_printf("%p", NULL));
//     printf("%d\n", printf("%p", NULL));

//     %d or %i
//     int num = 4;
//     printf("%d\n", ft_printf("%d", num));
//     printf("%d\n", printf("%d\n", num));

//     %u
//     printf("%d\n", ft_printf("%u", 4294967295));
//     printf("%d\n", printf("%u\n", 4294967295));

//     %x and %X
//     printf("%d\n", ft_printf("%x", -2));
//     printf("%d\n", printf("%x", 97));
//     printf("%d\n", ft_printf("%X", -2));
//     printf("%d\n", printf("%X", -2));

//     %%
//     printf("%d\n", ft_printf("%%", "tseting"));

//     printf("%i\n", "testing");
//     printf("%d\n", ft_printf("%p", 'a'));
//     ft_printf("%s %s", "testing", "yes");
// }