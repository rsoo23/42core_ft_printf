/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:26:29 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/02 13:26:29 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		ft_check_assign_form(const char **s, t_form *form)
{
	(*s)++;
	while (**s)
	{
		if (ft_valid_flag(**s, "-+0# "))
			ft_assign_flag(s, form);
		if (**s >= '1' && **s <= '9')
			ft_assign_num(s, form);
		if (**s == '.')
		{
			form->prec_exist = 1;
			(*s)++;
			ft_check_assign_prec(**s, s, form);
			(*s)++;
		}
		if (ft_valid_spec(**s, "cspdiuxX%"))
		{
			form->spec = **s;
			return (1);
		}
	}
	return (ft_putstr("Format error: %[flag][mfw][.precision][spec]"));
}

int		ft_valid_flag(const char s, char *flag_str)
{
	while (*flag_str)
	{
		if (s == *flag_str)
			return (1);
		flag_str++;
	}
	return (0);
}

int		ft_assign_flag(const char **s, t_form *form)
{
	while (ft_valid_flag(**s, "-+0# "))
	{
		if (**s == '#')
			form->hash++; 
		else if (**s == '0')
			form->zero++; 
		else if (**s == '+')
			form->plus++; 
		else if (**s == '-')
			form->minus++; 
		else if (**s == ' ')
			form->space++;
		else if (ft_valid_input(**s, "123456789.cspdiuxX%"))
			return (ft_putstr("Flag error: valid = #0+-space"));
		(*s)++;
	}
	return (1);
}

int		ft_check_assign_prec(const char nb, const char **s, t_form *form)
{
	if (nb >= '0' && nb <= '9')
		ft_assign_num(s, form);
	else
		return (ft_putstr("Precision error: put int behind ."));
	return (1);
}

int		ft_valid_spec(const char s, char *spec_str)
{
	while (*spec_str)
	{
		if (s == *spec_str)
			return (1);
		spec_str++;
	}
	return (ft_putstr("Specifier error: valid = cspdiuxX%"));
}
