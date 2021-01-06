/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:46:59 by jdemenet          #+#    #+#             */
/*   Updated: 2021/01/06 10:47:01 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_print_c(t_arg *my_arg)
{
	my_arg->c = (char)my_arg->int_c;
	if (my_arg->width > 1)
		ft_case1_c(my_arg);
	else
		ft_putchar(my_arg->c, my_arg);
}

int			ft_case1_c(t_arg *my_arg)
{
	if (my_arg->width > 1 && my_arg->flag == '-')
	{
		ft_putchar(my_arg->c, my_arg);
		ft_putchar_end((my_arg->width - 1), ' ', my_arg);
		return (0);
	}
	if ((my_arg->width > 1 && my_arg->flag == '0'))
		ft_putchar_end((my_arg->width - 1), '0', my_arg);
	else if (my_arg->width > 1 && my_arg->flag != '-')
		ft_putchar_end((my_arg->width - 1), ' ', my_arg);
	ft_putchar(my_arg->c, my_arg);
	return (0);
}

void		ft_case4_d(int j, t_arg *my_arg)
{
	if (my_arg->d < 0)
	{
		ft_putchar('-', my_arg);
		ft_putchar('0', my_arg);
		my_arg->less = '-';
	}
	ft_putchar_end(j, '0', my_arg);
	ft_putnbr(my_arg->d, my_arg);
}
