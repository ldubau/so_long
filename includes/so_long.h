/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:39:05 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/05 13:37:19 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define TILE_SIZE 64

typedef struct s_pos
{
	int	x;
	int	y;
} t_pos;

typedef struct s_map
{
	char	*line;
	char	**array;
	int		width;
	int		height;
	int		total_collectibles;
	int		collected;
	t_pos	player;
}t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*textures;
	int		count;
	t_map	map;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit;
	t_img	collect;
} t_game;


# include "./Libft/get_next_line.h"
# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <stdbool.h>
# include <fcntl.h>


void	init_mlx(t_game *game);
int		close_game(t_game *game);
int		key_hook(int keycode, t_game *game);
void	draw_all(t_game *game);
void	load_textures(t_game *game);
void	free_all(t_game *game);
int		error_check(t_game *game);
void	map_buid(int fd, t_map *map);
int		error_message(int nbr);


#endif


// ccw so_long.c libft.a /home/leonpouet/Documents/so_long/get_next_line/get_next_line.c /home/leonpouet/Documents/so_long/get_next_line/get_next_line_utils.c -I/home/leonpouet/Documents/so_long/get_next_line
