/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:47:29 by jdemenet          #+#    #+#             */
/*   Updated: 2021/01/06 10:47:30 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_print_u(t_arg *my_arg)
{
	int nbr;
	int i;
	int j;

	if (my_arg->u >= 0)
		nbr = ft_nbr_d_size(my_arg->u, my_arg);
	else
		nbr = ft_unsigned_nbr((unsigned)my_arg->u);
	i = my_arg->width - nbr;
	j = my_arg->accuracy - nbr;
	if (my_arg->width < nbr || my_arg->accuracy < nbr)
		ft_case1_u(nbr, i, j, my_arg);
	else
		ft_case2_u(i, j, my_arg);
	return (0);
}

int		ft_case1_u(int nbr, int i, int j, t_arg *my_arg)
{
	if (my_arg->width > nbr && my_arg->flag == '-')
	{
		ft_putnbr_unsigned(my_arg->u, my_arg);
		ft_putchar_end(i, ' ', my_arg);
		return (0);
	}
	if ((my_arg->width > nbr && my_arg->flag == '0') && (my_arg->accuracy < 0))
		ft_putchar_end(i, '0', my_arg);
	else if (my_arg->width > nbr && my_arg->flag != '-')
		ft_putchar_end(i, ' ', my_arg);
	else if (my_arg->accuracy > nbr)
		ft_putchar_end(j, '0', my_arg);
	ft_putnbr_unsigned((unsigned)my_arg->u, my_arg);
	return (0);
}

int		ft_case2_u(int i, int j, t_arg *my_arg)
{
	if (my_arg->width > my_arg->accuracy && my_arg->flag == '-')
	{
		ft_putchar_end(j, '0', my_arg);
		ft_putnbr_unsigned(my_arg->u, my_arg);
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
	ft_putnbr_unsigned(my_arg->u, my_arg);
	return (0);
}

int		ft_unsigned_nbr(unsigned long int nb)
{
	int i;

	i = 1;
	while (nb >= 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
