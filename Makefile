NAME = so_long

SRCS = so_long.c init_mlx.c hooks.c draw_map.c textures.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./42-Libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBMLX_DIR = ./minilibx-linux
LIBMLX = $(LIBMLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
