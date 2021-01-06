/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:44:46 by jdemenet          #+#    #+#             */
/*   Updated: 2021/01/06 10:44:48 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_arg
{
	char			flag;
	int				width;
	int				accuracy;
	char			type;
	int				start;
	int				end;
	va_list			*ap;
	int				d;
	int				u;
	char			*s;
	int				int_c;
	char			c;
	void			*p;
	char			prefix[9];
	int				x;
	int				int_x;
	int				ret;
	char			less;
	char			empty;
	int				i;
	int				m;
	unsigned long	adr;
}					t_arg;

int					ft_printf(char *str, ...);
void				ft_print1(t_arg *my_arg);
void				ft_print2(t_arg *my_arg, char *str);
int					ft_parse(char *str, int i, t_arg *my_arg);
int					ft_strlen(char *str);
void				ft_putchar(char c, t_arg *my_arg);
int					ft_find_char(char *str, char c, int first, int end);
int					ft_atoi(char *str);
int					ft_putstr(char *s, t_arg *my_arg);
int					ft_width_mem(char *str, int start, int end);
void				ft_get_width(char *str, int start, int end, t_arg *my_arg);
void				ft_get_flag(char *str, t_arg *my_arg);
int					ft_accuracy_mem(char *str, t_arg *my_arg);
void				ft_get_accuracy(char *str, int j, t_arg *my_arg,\
										int accuracy);
int					ft_nbr_d_size(long int nb, t_arg *my_arg);
int					ft_nbr_x_size(unsigned long i);
void				ft_putnbr(long int nb, t_arg *my_arg);
void				ft_putnbr_unsigned(unsigned int nb, t_arg *my_arg);
void				ft_putchar_end(int end, char c, t_arg *my_arg);
void				ft_print_d(t_arg *my_arg);
int					ft_case3_d(int i, int j, t_arg *my_arg);
int					ft_case2_d(int i, int j, t_arg *my_arg);
int					ft_case5_d(long int nb_d, int j, t_arg *my_arg);
int					ft_case1_d(long int nb_d, int i, int j, t_arg *my_arg);
void				ft_case4_d(int j, t_arg *my_arg);
void				ft_print_c(t_arg *my_arg);
int					ft_case1_c(t_arg *my_arg);
void				ft_print_s(t_arg *my_arg);
void				ft_case1_s(int nbr, int i, t_arg *my_arg);
void				ft_case2_s(int i, t_arg *my_arg);
void				ft_case3_s(int nbr, int i, t_arg *my_arg);
void				ft_case4_s(int i, t_arg *my_arg);
void				ft_print_x(t_arg *my_arg);
void				ft_positive_x(t_arg *my_arg, char *base);
void				ft_negative_x(t_arg *my_arg, unsigned int x, char *base);
int					ft_case1_x(int nbr, int j, t_arg *my_arg, char *charx);
int					ft_case2_x(int i, int j, t_arg *my_arg, char *charx);
void				ft_case1_s(int nbr, int i, t_arg *my_arg);
void				ft_case2_s(int i, t_arg *my_arg);
void				ft_case3_s(int nbr, int i, t_arg *my_arg);
void				ft_case4_s(int i, t_arg *my_arg);
int					ft_print_u(t_arg *my_arg);
int					ft_case1_u(int nbr, int i, int j, t_arg *my_arg);
int					ft_case2_u(int i, int j, t_arg *my_arg);
int					ft_unsigned_nbr(unsigned long int nb);
void				ft_print_p(t_arg *my_arg);
void				ft_case1_p(t_arg *my_arg, char *char_p);
void				ft_case2_p(t_arg *my_arg, char *char_p);
void				ft_print_0(t_arg *my_arg, char *str);
void				ft_case1_0(t_arg *my_arg, int i, char *str);

#endif
