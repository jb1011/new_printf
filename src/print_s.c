#include "../include/ft_printf.h"

void	ft_print_s(t_arg *my_arg)
{
	int nbr;
	int i;

	nbr = ft_strlen(my_arg->s);
	i = my_arg->width - nbr;
	if (my_arg->flag != '-')
	{
		if (my_arg->width <= nbr || (my_arg->accuracy >= nbr \
				|| my_arg->accuracy <= -1))
			ft_case1_s(nbr, i, my_arg);
		else if (my_arg->width > nbr && my_arg->accuracy < nbr)
			ft_case2_s(0, my_arg);
	}
	else
	{
		if (my_arg->width <= nbr || (my_arg->accuracy >= nbr \
				|| my_arg->accuracy <= -1))
			ft_case3_s(nbr, i, my_arg);
		else if (my_arg->width > nbr && my_arg->accuracy < nbr)
			ft_case4_s(0, my_arg);
	}
}

void	ft_case1_s(int nbr, int i, t_arg *my_arg)
{
	if (my_arg->width > nbr)
	{
		ft_putchar_end(i, ' ', my_arg);
		ft_putstr(my_arg->s, my_arg);
	}
	else if (my_arg->accuracy >= 0 && my_arg->accuracy < nbr)
	{
		ft_putchar_end((my_arg->width - my_arg->accuracy), ' ', my_arg);
		i = 0;
		while (i < my_arg->accuracy)
		{
			ft_putchar(my_arg->s[i], my_arg);
			i++;
		}
	}
	else
		ft_putstr(my_arg->s, my_arg);
}

void	ft_case2_s(int i, t_arg *my_arg)
{
	while (i < (my_arg->width - my_arg->accuracy))
	{
		ft_putchar(' ', my_arg);
		i++;
	}
	i = 0;
	while (i < my_arg->accuracy)
	{
		ft_putchar(my_arg->s[i], my_arg);
		i++;
	}
}

void	ft_case3_s(int nbr, int i, t_arg *my_arg)
{
	if (my_arg->width > nbr)
	{
		ft_putstr(my_arg->s, my_arg);
		ft_putchar_end(i, ' ', my_arg);
	}
	else if (my_arg->accuracy >= 0 && my_arg->accuracy < nbr)
	{
		i = 0;
		while (i < my_arg->accuracy)
		{
			ft_putchar(my_arg->s[i], my_arg);
			i++;
		}
		ft_putchar_end((my_arg->width - my_arg->accuracy), ' ', my_arg);
	}
	else
		ft_putstr(my_arg->s, my_arg);
}

void	ft_case4_s(int i, t_arg *my_arg)
{
	while (i < my_arg->accuracy)
	{
		ft_putchar(my_arg->s[i], my_arg);
		i++;
	}
	i = 0;
	while (i < (my_arg->width - my_arg->accuracy))
	{
		ft_putchar(' ', my_arg);
		i++;
	}
}
