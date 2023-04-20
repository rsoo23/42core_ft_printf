/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:14:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/01 21:14:30 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
// #include <stdio.h>

typedef struct s_form
{
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		min_fw;
	int		prec_exist;
	int		prec;
	int		form_len;
	char	spec;
}				t_form;

int		ft_parse(va_list ap, const char **s);
// ft_format_check.c
int		ft_valid_flag(const char s, char *flag_str);
int		ft_valid_assign_spec(const char s, char *spec_str, t_form *form);
int		ft_assign_flag(const char **s, t_form *form);
int		ft_check_assign_form(const char **s, t_form *form);
int		ft_check_assign_prec(const char nb, const char **s, t_form *form);
// ft_format_check_1.c
int		ft_check_flag_dup(t_form *form);
int		ft_check_rule(t_form *form);
// ft_utils.c
void	ft_init_form(t_form *form);
void	ft_putchar_b(char c, t_form *form);
void	ft_putstr_b(char *s, t_form *form);
void	ft_putstr_prec(char *s, t_form *form);
// ft_utils_1.c
int		ft_valid_input(const char c, char *str);
void	ft_put_zero_space(t_form *form);
int		ft_putstr(char *str);
int		ft_putchar(char c);
char	*ft_strdup(const char *s);
// ft_print_hex.c
int		ft_hex_len(uintptr_t nb);
void	ft_puthex_hash_zero(t_form *form);
void	ft_puthex(unsigned int nb, t_form *form);
void	ft_puthex_b(unsigned int nb, t_form *form);
void	ft_puthex_hash(unsigned int nb, t_form *form);
// ft_print_ptr.c
void	ft_put_ptr_b(uintptr_t nb, t_form *form);
void	ft_puthex_ptr(uintptr_t nb);
int		ft_put_ptr(uintptr_t nb);
// ft_print_int.c
void	ft_putnbr_int(int nb);
void	ft_numlen_int_b(int nb, t_form *form);
void	ft_putnbr_int_b(int nb, t_form *form);
void	ft_int_space_plus(int nb, t_form *form);
// ft_print_uint.c
void	ft_uint_space_plus(int nb, t_form *form);
void	ft_putnbr_uint(unsigned int nb, t_form *form);
void	ft_numlen_uint_b(unsigned int nb, t_form *form);
void	ft_putnbr_uint_b(unsigned int nb, t_form *form);

#endif