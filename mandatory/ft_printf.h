/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:41:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/27 23:41:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_PRINTF_H
# define    FT_PRINTF_H

# include <stdlib.h> //write, malloc, free, exit
# include <stdarg.h> //va_start, va_arg, va_end, va_copy
# include <unistd.h>
# include <stdint.h> // for uintptr_t
// # include <stdio.h>

//ft_printf.c
int		ft_printf(const char *format, ...);
int		ft_parse(va_list ap, const char *s);
//ft_print_hex.c
int		ft_puthex(unsigned int nb, char format);
int		ft_hex_len(uintptr_t nb);
//ft_print_nbr.c
int		ft_numlen_int(int nb);
int		ft_putnbr_int(int nb);
int		ft_numlen_uint(unsigned int nb);
int		ft_putnbr_uint(unsigned int nb);
//ft_print_ptr.c
int		ft_put_ptr(uintptr_t nb);
void	ft_puthex_ptr(uintptr_t nb);
//ft_utils_m.c
int		ft_putchar(char c);
int		ft_putstr(char *str);
//ft_format_check.c
int		ft_checkspec_all(const char *s);
char	ft_find_char(const char *s);
int		ft_valid_spec(char spec, char *spec_str);

#endif