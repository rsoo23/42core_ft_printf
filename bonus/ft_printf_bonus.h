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

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_form
{
	int		hash; // #
	int		zero; // 0
	int		plus; // +
	int		minus; // -
	int		space; // ' ' 
	int		min_fw; // int
	int		prec_exist; // indicates presence of .
	int		prec;   // int (0 onwards)
	int		form_len; 
	char	spec;   // char
} t_form;

// ft_format_check_bonus.c
int		ft_check_assign_form(const char **s, t_form *form);
int		ft_check_assign_prec(const char nb, const char **s, t_form *form);
int		ft_valid_flag(const char s, char *flag_str);
int		ft_assign_flag(const char **s, t_form *form);
int		ft_valid_spec(const char s, char *spec_str);
// ft_format_check_bonus1.c
int		ft_check_rule(t_form *form);
int		ft_check_flag_dup(t_form *form);
// ft_utils_bonus.c
int		ft_parse_bonus(va_list ap, const char **s);
void	ft_init_form(t_form *form);
void	ft_putchar_b(char c, t_form *form);
// void	ft_putstr_b(char *s, t_form *form);
void	ft_assign_num(const char **s, t_form *form);
// ft_utils_bonus1.c
int		ft_putstr(char *str);
int		ft_valid_input(const char c, char *str);
int		ft_putchar(char c);
// ft_print_hex_bonus.c
int		ft_hex_len(uintptr_t nb);
void	ft_puthex(unsigned int nb, t_form *form);
void	ft_puthex_hash_zero(t_form *form);
void	ft_puthex_hash(unsigned int nb, t_form *form);
void    ft_puthex_b(unsigned int nb, t_form *form);
// ft_print_ptr_bonus.c
void	ft_put_ptr_b(uintptr_t nb, t_form *form);
int		ft_put_ptr(uintptr_t nb);
void	ft_puthex_ptr(uintptr_t nb);
// ft_print_int_bonus.c
void    ft_putnbr_int_b(int nb, t_form *form);
void	ft_putnbr_int(int nb, t_form *form);
void	ft_numlen_int_b(int nb, t_form *form);
void	ft_int_space_plus(int nb, t_form *form);
// ft_print_uint_bonus.c
void	ft_numlen_uint_b(unsigned int nb, t_form *form);
void	ft_putnbr_uint(unsigned int nb, t_form *form);
void    ft_putnbr_uint_b(unsigned int nb, t_form *form);
void	ft_uint_space_plus(int nb, t_form *form);

#endif