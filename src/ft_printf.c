
#include "../include/ft_printf.h"

void	ft_print1(t_arg *my_arg)
{
	if (my_arg->type == 'i' || my_arg->type == 'd')
	{
		my_arg->d = va_arg(*my_arg->ap, int);
		ft_print_d(my_arg);
	}
	else if (my_arg->type == 's')
	{
		my_arg->s = (char *)(va_arg(*my_arg->ap, char*));
		if (!my_arg->s)
			my_arg->s = "(null)";
		ft_print_s(my_arg);
	}
	else if (my_arg->type == 'c')
	{
		my_arg->int_c = va_arg(*my_arg->ap, int);
		ft_print_c(my_arg);
	}
}

void	ft_print2(t_arg *my_arg, char *str)
{
	if (my_arg->type == 'p')
	{
		my_arg->p = va_arg(*my_arg->ap, void*);
		my_arg->adr = (unsigned long)my_arg->p;
		my_arg->end = ft_nbr_x_size(my_arg->adr) + 1;
		ft_print_p(my_arg);
	}
	else if (my_arg->type == 'u')
	{
		my_arg->u = va_arg(*my_arg->ap, int);
		ft_print_u(my_arg);
	}
	else if (my_arg->type == 'x' || my_arg->type == 'X')
	{
		my_arg->x = va_arg(*my_arg->ap, int);
		ft_print_x(my_arg);
	}
	else if (my_arg->type == '0')
		ft_print_0(my_arg, str);
}

int		ft_parse(char *str, int i, t_arg *my_arg)
{
	int j;
	int	accuracy;

	my_arg->start = i;
	j = -1;
	while (((j = ft_find_char("cspdiuxX", str[i], 0, 8)) < 0) && str[i])
		i++;
	if (j == -1)
		my_arg->type = '0';
	else
		my_arg->type = str[i];
	my_arg->end = i;
	my_arg->m = ft_width_mem(str, my_arg->start, i);
	ft_get_width(str, my_arg->start, i, my_arg);
	ft_get_flag(str, my_arg);
	accuracy = ft_accuracy_mem(str, my_arg);
	ft_get_accuracy(str, 0, my_arg, accuracy);
	if (my_arg->type == 'd' || my_arg->type == 'i' || my_arg->type == 's'\
			|| my_arg->type == 'c')
		ft_print1(my_arg);
	else
		ft_print2(my_arg, str);
	return (i + 1);
}

int		ft_printf(char *str, ...)
{
	int		i;
	t_arg	my_arg;
	va_list	ap;

	i = 0;
	my_arg.ret = 0;
	va_start(ap, str);
	my_arg.ap = &ap;
	while (str[i] && i < ft_strlen(str))
	{
		while (str[i] != '%' && str[i])
			ft_putchar(str[i++], &my_arg);
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar(str[i], &my_arg);
			i += 2;
		}
		if (str[i] == '%' && str[i + 1] != '%')
			i = ft_parse(str, i, &my_arg);
	}
	return (my_arg.ret);
}
