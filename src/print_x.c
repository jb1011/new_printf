/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:47:38 by jdemenet          #+#    #+#             */
/*   Updated: 2021/01/06 10:47:40 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_x(t_arg *my_arg)
{
	unsigned int	my_x;
	char			*base;

	my_x = (unsigned)my_arg->x;
	if (my_arg->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (my_arg->x >= 0)
	{
		my_arg->end = ft_nbr_x_size((unsigned)my_arg->x) + 1;
		ft_positive_x(my_arg, base);
	}
	else
	{
		my_arg->end = ft_nbr_x_size(my_x) + 1;
		ft_negative_x(my_arg, my_x, base);
	}
}

void	ft_positive_x(t_arg *my_arg, char *base)
{
	int		x;
	char	char_x[my_arg->end];

	x = my_arg->x;
	char_x[my_arg->end] = '\0';
	my_arg->end = my_arg->end - 1;
	while (my_arg->end >= 0)
	{
		char_x[my_arg->end] = (base[(x % 16)]);
		x = x / 16;
		my_arg->end--;
	}
	x = ft_strlen(char_x);
	my_arg->i = my_arg->width - x;
	if (my_arg->width < x || my_arg->accuracy < x)
		ft_case1_x(x, (my_arg->accuracy - x), my_arg, char_x);
	else
		ft_case2_x((my_arg->width - x), (my_arg->accuracy - x), my_arg, char_x);
}

void	ft_negative_x(t_arg *my_arg, unsigned int my_x, char *base)
{
	char	charx[my_arg->end];
	int		x;

	charx[my_arg->end] = '\0';
	my_arg->end = my_arg->end - 1;
	while (my_arg->end >= 0)
	{
		charx[my_arg->end] = (base[(my_x % 16)]);
		my_x /= 16;
		my_arg->end--;
	}
	x = ft_strlen(charx);
	my_arg->i = my_arg->width - x;
	if (my_arg->width < x || my_arg->accuracy < x)
		ft_case1_x(x, (my_arg->accuracy - x), my_arg, charx);
	else
		ft_case2_x((my_arg->width - x), (my_arg->accuracy - x), my_arg, charx);
}

int		ft_case1_x(int nbr, int j, t_arg *my_arg, char *charx)
{
	if (my_arg->width > nbr && my_arg->flag == '-')
	{
		if (my_arg->accuracy == 0 && my_arg->x == 0)
			ft_putchar(' ', my_arg);
		else
			ft_putstr(charx, my_arg);
		ft_putchar_end(my_arg->i, ' ', my_arg);
		return (0);
	}
	if ((my_arg->width > nbr && my_arg->flag == '0') && (my_arg->accuracy < 0))
		ft_putchar_end(my_arg->i, '0', my_arg);
	else if (my_arg->width > nbr && my_arg->flag != '-')
		ft_putchar_end(my_arg->i, ' ', my_arg);
	if (my_arg->accuracy > nbr)
		ft_putchar_end(j, '0', my_arg);
	if (my_arg->accuracy == 0 && my_arg->x == 0 && my_arg->width > 0)
		ft_putchar(' ', my_arg);
	if (my_arg->accuracy == 0 && my_arg->x == 0)
		return (0);
	ft_putstr(charx, my_arg);
	return (0);
}

int		ft_case2_x(int i, int j, t_arg *my_arg, char *charx)
{
	if (my_arg->width > my_arg->accuracy && my_arg->flag == '-')
	{
		ft_putchar_end(j, '0', my_arg);
		ft_putstr(charx, my_arg);
		ft_putchar_end(i - j, ' ', my_arg);
		return (0);
	}
	if (my_arg->width > my_arg->accuracy && my_arg->flag != '-')
	{
		ft_putchar_end(i - j, ' ', my_arg);
		ft_putchar_end(j, '0', my_arg);
	}
	else
		ft_putchar_end(j, '0', my_arg);
	ft_putstr(charx, my_arg);
	return (0);
}
