/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:36:26 by ldubau            #+#    #+#             */
/*   Updated: 2026/03/06 08:31:29 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game, char data, int i, int j)
{
	if (data == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data == 'E' && game->map.collected != game->map.total_collectibles)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data == 'E' && game->map.collected == game->map.total_collectibles)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data == 'P')
	{
		game->map.array[i][j] = '0';
		game->map.player.x = j;
		game->map.player.y = i;
	}
}

void	draw_all(t_game *game)
{
	int		i;
	int		j;
	char	data;

	i = 0;
	while (game->map.height > i)
	{
		j = 0;
		while (game->map.width > j)
		{
			data = game->map.array[i][j];
			if (data == '1' || data == '0' || data == 'C'
				|| data == 'E' || data == 'P')
				draw_map(game, data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx,
		game->win, game->player.img,
		game->map.player.x * TILE_SIZE,
		game->map.player.y * TILE_SIZE);
}
