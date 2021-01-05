#include "../include/ft_printf.h"

int		ft_width_mem(char *str, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end && str[start] != '.')
	{
		if (ft_find_char("123456789", str[start], 0, 9) >= 0)
		{
			while ((ft_find_char("0123456789", str[start], 0, 10)) >= 0)
			{
				i++;
				start++;
			}
			break ;
		}
		start++;
	}
	return (i);
}

void	ft_get_width(char *str, int start, int end, t_arg *my_arg)
{
	char	width[my_arg->m + 1];

	my_arg->m = 0;
	width[0] = '\0';
	while (start <= end && str[start] != '.')
	{
		if ((ft_find_char("123456789", str[start], 0, 9)) >= 0)
		{
			while ((ft_find_char("0123456789", str[start + my_arg->m], 0, 10)) >= 0)
			{
				width[my_arg->m] = str[start + my_arg->m];
				my_arg->m++;
			}
			width[my_arg->m] = '\0';
			break ;
		}
		if (str[start] == '*')
		{
			my_arg->width = va_arg(*my_arg->ap, int);
			return ;
		}
		start++;
	}
	my_arg->width = ft_atoi(width);
}

void	ft_get_flag(char *str, t_arg *my_arg)
{
	int i;

	i = my_arg->start;
	while ((str[i] < '1' || str[i] > '9') && i < my_arg->end)
		i++;
	if ((ft_find_char(str, '0', my_arg->start, i)) >= 0)
		my_arg->flag = '0';
	else
		my_arg->flag = 'x';
	if ((ft_find_char(str, '-', my_arg->start, i)) >= 0)
		my_arg->flag = '-';
	if (my_arg->width < 0)
	{
		my_arg->width = my_arg->width * -1;
		my_arg->flag = '-';
	}
}

int		ft_accuracy_mem(char *str, t_arg *my_arg)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if ((i = ft_find_char(str, '.', my_arg->start, my_arg->end)) >= 0)
	{
		i++;
		while ((ft_find_char("0123456789", str[i + j], 0, 10)) >= 0)
			j++;
		return (j);
	}
	return (0);
}

void	ft_get_accuracy(char *str, int j, t_arg *my_arg, int accuracy)
{
	int		i;
	char	prec[accuracy + 1];

	i = -1;
	prec[0] = '\0';
	if ((i = ft_find_char(str, '.', my_arg->start, my_arg->end)) >= 0)
	{
		i++;
		while ((str[i] >= '0' && str[i] <= '9') && i < my_arg->end)
		{
			prec[j] = str[i];
			j++;
			i++;
		}
		if (str[i] == '*')
		{
			my_arg->accuracy = va_arg(*my_arg->ap, int);
			return ;
		}
		prec[j] = '\0';
		my_arg->accuracy = ft_atoi(prec);
	}
	else
		my_arg->accuracy = -1;
}