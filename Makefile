NAME			= libftprintf.a

SRCS			= \
					src/ft_printf.c \
					src/parser_sub_functions.c \
					src/print_0.c \
					src/print_c.c \
					src/print_d.c \
					src/print_p.c \
					src/print_s.c \
					src/print_u.c \
					src/print_x.c \
					src/utils1.c \
					src/utils2.c

OBJECTS 		= \
					ft_printf.o \
					parser_sub_functions.o \
					print_0.o \
					print_c.o \
					print_d.o \
					print_p.o \
					print_s.o \
					print_u.o \
					print_x.o \
					utils1.o \
					utils2.o

INCLUDES = include/ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: 		all fclean clean re
