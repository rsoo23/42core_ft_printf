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

int		ft_checkspec_all(const char *s)
{
	if (ft_find_char(s) == '0')
		return (ft_putstr("Error: missing specifier, select one: cspdiuxX%"));
	if (ft_spec_valid(ft_find_char(s), "cspdiuxX%") == 0)
		return (ft_putstr("Error: invalid specifier, select one: cspdiuxX%"));
	return (1);
}

// check if there is any char after %
char	ft_find_char(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			return (s[i]);
		if (s[i] >= 'A' && s[i] <= 'Z')
			return (s[i]);
		i++;
	}
	return ('0');
}

// check if the char is valid
int		ft_spec_valid(char spec, char *spec_str)
{
	while (*spec_str)
	{
		if (spec == *spec_str)
			return (1);
		spec_str++;
	}
	return (0);
}

// void	ft_check_format()
// {
// 	int	num;

// 	num = 0;
// 	while (ft_valid_flag(s[i]))
// 		i++;
// 	while (ft_isnum(s[i]))
// 	{

// 	}
	
// 		i++;
// 	if (s[i] == '.')
	
// }