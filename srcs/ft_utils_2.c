/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:08:39 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/24 22:08:39 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    ft_put_nbr_zero_space(int nb, t_form *form)
{
    while (form->form_len < form->min_fw)
	{
		if (form->prec_exist && form->prec == 0 && nb == 0)
			ft_putchar(' ');
		else if (form->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		form->form_len++;
	}
}
