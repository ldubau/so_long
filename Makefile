NAME = so_long

SRCS = so_long.c init_mlx.c hooks.c draw_map.c textures.c error_check.c\
	parse.c error_message.c

SRCS_DIR = sources/
OBJS_DIR = objects/
INCLUDE_DIR = ./includes

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS := $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBMLX_DIR = ./minilibx-linux
LIBMLX = $(LIBMLX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(LIBMLX_DIR) -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(FT_PRINTF) $(LIBFT) -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
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
	make -C $(LIBMLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
