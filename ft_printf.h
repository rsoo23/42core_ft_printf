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

#include <stdlib.h> //write, malloc, free, exit
#include <stdarg.h> //va_start, va_arg, va_end, va_copy
#include <unistd.h>

//ft_std.c
int     ft_putchar(char c);
int     ft_putstr(char *str);
int     ft_numlen_int(int nb);
int     ft_putnbr_int(int nb);
int     ft_numlen_uint(unsigned int nb);
int     ft_putnbr_uint(unsigned int nb);
int     ft_puthex_low(int nb);
int     ft_puthex_up(int nb);
// int     ft_strlen(char *str);

int     ft_printf(const char *format,...);

#endif