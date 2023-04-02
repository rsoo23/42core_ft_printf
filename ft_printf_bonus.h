/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:14:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/01 21:14:30 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_BONUS_H
# define FT_PRINT_BONUS_H

typedef struct s_form
{
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		min_fw;
	int		prec;
	char	spec;
} t_form;


// ft_format_check_bonus.c
int		ft_check_assign_form(t_form *form, const char *s);
int		ft_valid_flag(char f, t_form *form);
int		ft_isnum(char nb);
int		ft_check_prec(char nb, const char *s, t_form *form);
int		ft_valid_spec_bonus(char s, t_form *form, char *spec_str);
int		ft_check_rule(t_form *form);
int		ft_check_flag_dup(t_form *form);
// ft_utils_bonus.c
void    ft_init_form(t_form *form);
int		ft_parse_bonus(va_list ap, const char *s);
int		ft_atoi(const char *str);

#endif