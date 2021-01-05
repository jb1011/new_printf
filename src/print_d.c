#include "../include/ft_printf.h"

void	ft_print_d(t_arg *my_arg)
{
	long int    nb_d;
	int			i;
	int			j;

	nb_d = ft_nbr_d_size(my_arg->d, my_arg);
	i = my_arg->width - nb_d;
	j = my_arg->accuracy - nb_d;
	my_arg->less = 'x';
	if (my_arg->width <= nb_d || my_arg->accuracy < nb_d)
		ft_case1_d(nb_d, i, j, my_arg);
	else
	{
		if (my_arg->width > my_arg->accuracy && my_arg->flag == '-')
			ft_case2_d(i, j, my_arg);
		else if (my_arg->width > my_arg->accuracy && my_arg->flag != '-')
			ft_case3_d(i, j, my_arg);
		else
			ft_case4_d(j, my_arg);
	}
}

int		ft_case1_d(long int nb_d, int i, int j, t_arg *my_arg)
{
	if (my_arg->width > nb_d && my_arg->flag == '-')
	{
		if (my_arg->accuracy == 0 && my_arg->d == 0)
			ft_putchar(' ', my_arg);
		else
			ft_putnbr(my_arg->d, my_arg);
		ft_putchar_end(i, ' ', my_arg);
		return (0);
	}
	else if ((my_arg->width > nb_d && my_arg->flag == '0') && (my_arg->accuracy < 0))
	{
		if (my_arg->d < 0)
		{
			ft_putchar('-', my_arg);
			my_arg->less = '-';
		}
		ft_putchar_end(i, '0', my_arg);
	}
	else if (my_arg->width > nb_d && my_arg->flag != '-')
		ft_putchar_end(i, ' ', my_arg);
	ft_case5_d(nb_d, j, my_arg);
	return (0);
}

int		ft_case5_d(long int nb_d, int j, t_arg *my_arg)
{
	if (my_arg->accuracy >= nb_d)
	{
		if (my_arg->d < 0)
		{
			ft_putchar('-', my_arg);
			ft_putchar('0', my_arg);
			my_arg->less = '-';
		}
		ft_putchar_end(j, '0', my_arg);
	}
	if (my_arg->accuracy == 0 && my_arg->d == 0 && my_arg->width > 0)
		ft_putchar(' ', my_arg);
	if (my_arg->accuracy == 0 && my_arg->d == 0)
		return (0);
	ft_putnbr(my_arg->d, my_arg);
	return (0);
}

int		ft_case2_d(int i,  int j, t_arg *my_arg)
{
	if (my_arg->d < 0)
	{
		ft_putchar('-', my_arg);
		ft_putchar('0', my_arg);
		my_arg->less = '-';
	}
	ft_putchar_end(j, '0', my_arg);
	ft_putnbr(my_arg->d, my_arg);
	if (my_arg->d < 0)
		j++;
	ft_putchar_end(i - j, ' ', my_arg);
	return (0);
}

int		ft_case3_d(int i, int j, t_arg *my_arg)
{
	if (my_arg->width > my_arg->accuracy && my_arg->flag != '-')
	{
		if (my_arg->d < 0)
			ft_putchar_end(i - (j + 1), ' ', my_arg);
		else
			ft_putchar_end(i - j, ' ', my_arg);
		if (my_arg->d < 0)
		{
			ft_putchar('-', my_arg);
			ft_putchar('0', my_arg);
			my_arg->less = '-';
		}
		ft_putchar_end(j, '0', my_arg);
	}
	ft_putnbr(my_arg->d, my_arg);
	return (0);
}