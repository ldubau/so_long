NAME = so_long

SRCS = so_long.c init_mlx.c hooks.c draw_map.c textures.c error.c parse.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBMLX_DIR = ./minilibx-linux
LIBMLX = $(LIBMLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(FT_PRINTF) $(LIBFT) -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	make -C $(LIBMLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	make -C $(LIBMLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
