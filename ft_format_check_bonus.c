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
#include "ft_printf.h"

int		ft_check_assign_form(t_form *form, const char *s)
{
	s++;
	while (*s)
	{
		while (ft_valid_flag(*s, &form))
			s++;
		if (ft_isnum(*s))
		{
			form->min_fw = ft_atoi(s);
			s++;
		}
		if (*s == '.')
		{
			s++;
			ft_check_prec(*s, s, &form);
			s++;
		}
		if (ft_valid_spec_bonus(*s, &form, "cspdiuxX%"))
			s++;
		if (*s == '\0')
			return (1);
		else
			return (ft_putstr("Format error: %[flag][mfw][.precision][spec]"));
	}
}

int		ft_valid_flag(char f, t_form *form)
{
	if (*s == '#')
		form->hash++; 
	else if (*s == '0')
		form->zero++; 
	else if (*s == '+')
		form->plus++; 
	else if (*s == '-')
		form->minus++; 
	else if (*s == ' ')
		form->space++;
	else
		return (ft_putstr("Flag error: valid = #0+-space"))
	return (1);
}

int		ft_isnum(char nb)
{
	return (nb >= '1' && nb <= '9');
}

int		ft_check_prec(char nb, const char *s, t_form *form)
{
	if (ft_isascii_num(*s))
		form->prec = ft_atoi(s);
	else
		return (ft_putstr("Precision error: put int behind ."));
	return (1);
}

int		ft_valid_spec_bonus(char s, t_form *form, char *spec_str)
{
	while (*spec_str)
	{
		if (s == *spec_str)
		{
			form->spec = s;
			return (1);
		}
		spec_str++;
	}
	return (ft_putstr("Flag error: valid = #0+-space"));
}

// checks for special rules, '-0', ' +', flag duplicates, 
int		ft_check_rule(t_form *form)
{
	if (ft_check_flag_dup(form) != 1)
		return (0);
	if (form->hash == 1 && !ft_valid_spec(form->spec, "xX"))
		return (ft_putstr("Error: # only compatible with %xX"));
	if (form->zero == 1 && !ft_valid_spec(form->spec, "diuxX"))
		return (ft_putstr("Error: 0 only compatible with %diuxX"));
	if (form->plus == 1 && !ft_valid_spec(form->spec, "diu"))
		return (ft_putstr("Error: + only compatible with %diu"));
	if (form->space == 1 && !ft_valid_spec(form->spec, "diu"))
		return (ft_putstr("Error: space only compatible with %diu"));
	if (form->prec != 0 && !ft_valid_spec(form->spec, "s"))
		return (ft_putstr("Error: prec only compatible with %s"));
	if (form->minus == 1 && form->zero == 1) // -0: ignore zero
		form->zero = 0;
	if (form->space == 1 && form->plus == 1) // +space: ignore space
		form->space = 0;
	return (1);
}

int		ft_check_flag_dup(t_form *form)
{
	if (form->hash != 1)
		return (ft_putstr("Flag duplicate error: #"));
	if (form->zero != 1)
		return (ft_putstr("Flag duplicate error: 0"));
	if (form->plus != 1)
		return (ft_putstr("Flag duplicate error: +"));
	if (form->minus != 1)
		return (ft_putstr("Flag duplicate error: -"));
	if (form->space != 1)
		return (ft_putstr("Flag duplicate error: space"));
	return (1);
}