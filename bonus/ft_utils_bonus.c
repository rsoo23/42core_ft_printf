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

#include "ft_printf_bonus.h"

void	ft_init_form(t_form *form)
{
	form->hash = 0;
	form->zero = 0;
	form->plus = 0;
	form->minus = 0;
	form->space = 0;
	form->min_fw = 0;
	form->prec_exist = 0;
	form->prec = 0;
	form->form_len = 0;
	form->spec = '0';
}

int	ft_parse_bonus(va_list ap, const char **s)
{
	t_form	*form;

	form = malloc(sizeof(t_form));
	ft_init_form(form);
	if (ft_check_assign_form(s, form) && ft_check_rule(form))
	{
		if (form->spec == 'c')
			ft_putchar_b(va_arg(ap, int), form);
		else if (form->spec == 'p')
			ft_put_ptr_b(va_arg(ap, uintptr_t), form);
		else if (form->spec == 'x' || form->spec == 'X')
			ft_puthex_b(va_arg(ap, unsigned int), form);
		else if (form->spec == '%')
			form->form_len += ft_putchar('%');
		else if (form->spec == 'd' || form->spec == 'i')
			ft_putnbr_int_b(va_arg(ap, int), form);
		else if (form->spec == 'u')
			ft_putnbr_uint_b(va_arg(ap, unsigned int), form);
		else if (form->spec == 's')
			ft_putstr_b(va_arg(ap, char *), form);
	}
	return (form->form_len);
}

void	ft_putchar_b(char c, t_form *form)
{
	if (form->minus)
		form->form_len += ft_putchar(c);
	while (form->form_len < form->min_fw - 1)
	{
		ft_putchar(' ');
		form->form_len++;
	}
	if (!(form->minus))
		form->form_len += ft_putchar(c);
}

void	ft_putstr_b(char *s, t_form *form)
{
	if (form->minus == 1)
		ft_putstr_prec(s, form);
	while (form->form_len < form->min_fw)
	{
		ft_putchar(' ');
		form->form_len++;
	}
	if (form->minus == 0)
		ft_putstr_prec(s, form);
}

void	ft_putstr_prec(char *s, t_form *form)
{
	if (form->prec_exist && form->prec < form->form_len)
	{
		while (form->form_len < form->prec)
		{
			ft_putchar(*s);
			s++;
			form->form_len++;
		}
	}
	else
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
			form->form_len++;
		}
	}
	return ;
}
