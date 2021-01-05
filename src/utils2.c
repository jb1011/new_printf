#include "../include/ft_printf.h"

int		ft_nbr_d_size(long int nb, t_arg *my_arg)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		if (my_arg->type != 'u')
			i = i + 1;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		ft_nbr_x_size(unsigned long i)
{
	int j;

	j = 0;
	while ((i = i / 16) > 0)
		j++;
	return (j);
}

void	ft_putnbr(long int nb, t_arg *my_arg)
{
	if (nb < 0)
	{
		if (my_arg->type != 'u' && my_arg->less == 'x')
			ft_putchar('-', my_arg);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, my_arg);
		ft_putnbr(nb % 10, my_arg);
	}
	else
		ft_putchar(nb + '0', my_arg);
}

void	ft_putnbr_unsigned(unsigned int nb, t_arg *my_arg)
{
	if (nb == 0 && my_arg->accuracy == 0)
	{
		if (my_arg->width > 0)
			ft_putchar(' ', my_arg);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, my_arg);
		ft_putnbr(nb % 10, my_arg);
	}
	else
		ft_putchar(nb + '0', my_arg);
}

void	ft_putchar_end(int end, char c, t_arg *my_arg)
{
	int i;

	i = 0;
	if (end < 0)
		return ;
	while (i < end)
	{
		my_arg->ret = my_arg->ret + 1;
		write(1, &c, 1);
		i++;
	}
}
