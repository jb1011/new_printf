
#include "../include/ft_printf.h"

void	ft_print_p(t_arg *my_arg)
{
	char	*base;
	char	char_p[my_arg->end];

	base = "0123456789abcdef";
	char_p[my_arg->end] = '\0';
	my_arg->end = my_arg->end - 1;
	while (my_arg->end >= 0)
	{
		char_p[my_arg->end] = base[(my_arg->adr % 16)];
		my_arg->adr = my_arg->adr / 16;
		my_arg->end--;
	}
	if (my_arg->width > ft_strlen(char_p))
		ft_case1_p(my_arg, char_p);
	else
		ft_case2_p(my_arg, char_p);
}

void	ft_case1_p(t_arg *my_arg, char *char_p)
{
	if (my_arg->flag == '-')
	{
		ft_case2_p(my_arg, char_p);
		ft_putchar_end((my_arg->width - (ft_strlen(char_p) + 2)), ' ', my_arg);
	}
	else if (my_arg->flag != '-')
	{
		ft_putchar_end((my_arg->width - (ft_strlen(char_p) + 2)), ' ', my_arg);
		ft_case2_p(my_arg, char_p);
	}
}

void	ft_case2_p(t_arg *my_arg, char *char_p)
{
	int i;

	i = 0;
	if ((my_arg->p == NULL && my_arg->accuracy == 0) && my_arg->width > 2)
		ft_putchar(' ', my_arg);
	ft_putchar('0', my_arg);
	ft_putchar('x', my_arg);
	if (my_arg->p == NULL && my_arg->accuracy == 0)
		return ;
	while (i < ft_strlen(char_p))
	{
		ft_putchar(char_p[i], my_arg);
		i++;
	}
}
