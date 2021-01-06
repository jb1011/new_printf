/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:46:51 by jdemenet          #+#    #+#             */
/*   Updated: 2021/01/06 10:46:53 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_0(t_arg *my_arg, char *str)
{
	int	i;

	i = my_arg->start + 1;
	if (my_arg->flag == '-')
	{
		ft_case1_0(my_arg, i, str);
		return ;
	}
	if (my_arg->flag == 'x' && my_arg->width > 0)
		ft_putchar_end((my_arg->width - 1), ' ', my_arg);
	if (my_arg->flag == '0' && my_arg->width > 0)
		ft_putchar_end((my_arg->width - 1), '0', my_arg);
	while (str[i] != '%' && i < my_arg->end)
		i++;
	while (i < my_arg->end)
	{
		ft_putchar(str[i], my_arg);
		i++;
	}
}

void	ft_case1_0(t_arg *my_arg, int i, char *str)
{
	ft_putchar('%', my_arg);
	ft_putchar_end((my_arg->width - 1), ' ', my_arg);
	while (str[i] != '%' && i < my_arg->end)
		i++;
	i++;
	while (i < my_arg->end)
	{
		ft_putchar(str[i], my_arg);
		i++;
	}
}
