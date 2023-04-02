/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:23:43 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/31 14:23:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_init_form(t_flag *form)
{
    form->hash = 0;
    form->zero = 0;
    form->plus = 0;
    form->minus = 0;
    form->space = 0;
    form->min_fw = 0;
    form->prec = 0;
    form->spec = '0';
}

int		ft_parse_bonus(va_list ap, const char *s)
{
	t_form  *form;

	form = malloc(sizeof(t_form));
    // ft_checkspec_all(s);
    ft_init_form();
	if (ft_check_assign_form(&form, s) && ft_check_rule(&form));
        
}

    if (*s == 's')
		len += ft_putstr(va_arg(ap, char*));
    else if (*s == 'c')
        len += ft_putchar(va_arg(ap, int)); // char promoted to int
    else if (*s == 'p')
        len += ft_put_ptr(va_arg(ap, uintptr_t));
    else if (*s == 'd' || *s == 'i')
        len += ft_putnbr_int(va_arg(ap, int));
    else if (*s == 'u')
        len += ft_putnbr_uint(va_arg(ap, unsigned int));
    else if (*s == 'x' || *s == 'X')
        len += ft_puthex(va_arg(ap, unsigned int), *s);
    else if (*s == '%')
        len += ft_put_percent();
    return (len);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (sign * number);
}