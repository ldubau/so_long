SRC = ft_printf.c check_format.c print_int.c print_hexa.c print_str.c\
	print_unsigned.c print_void.c putnbr_base.c ft_putnbr.c\
	ft_putchar.c

CC = cc -Werror -Wall -Wextra
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
