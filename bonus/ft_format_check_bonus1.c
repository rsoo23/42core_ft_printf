/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check_bonus1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:19:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/04 16:19:02 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	if (form->hash > 1)
		return (ft_putstr("Flag duplicate error: #"));
	if (form->zero > 1)
		return (ft_putstr("Flag duplicate error: 0"));
	if (form->plus > 1)
		return (ft_putstr("Flag duplicate error: +"));
	if (form->minus > 1)
		return (ft_putstr("Flag duplicate error: -"));
	if (form->space > 1)
		return (ft_putstr("Flag duplicate error: space"));
	return (1);
}
