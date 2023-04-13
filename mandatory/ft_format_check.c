/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:39:44 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/31 16:39:44 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkspec_all(const char *s)
{
	if (ft_find_char(s) == '0')
		return (ft_putstr("missing specifier, valid = cspdiuxX%"));
	if (ft_valid_spec(ft_find_char(s), "cspdiuxX") == 0)
		return (ft_putstr("invalid specifier, valid = cspdiuxX%"));
	return (1);
}

// check if there is any char after %
char	ft_find_char(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			return (s[i]);
		if (s[i] == '%')
			return ('%');
		i++;
	}
	return ('0');
}

// check if the char is valid
int	ft_valid_spec(char spec, char *spec_str)
{
	while (*spec_str)
	{
		if (spec == *spec_str || spec == '%')
			return (1);
		spec_str++;
	}
	return (0);
}
