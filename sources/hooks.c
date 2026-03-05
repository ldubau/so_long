/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:36:32 by ldubau            #+#    #+#             */
/*   Updated: 2026/03/05 12:39:04 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	if (!game)
		exit(0);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->collect.img)
		mlx_destroy_image(game->mlx, game->collect.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_all(game);
	exit(0);
	return (0);
}

int	moov_player(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == '1')
		return (0);
	if (game->map.array[y][x] == 'C')
	{
		game->map.array[y][x] = '0';
		game->map.collected++;
	}
	else if (game->map.array[y][x] == 'E')
	{
		if (game->map.collected == game->map.total_collectibles)
			close_game(game);
		else
			return (0);
	}
	game->count++;
	ft_printf("%d\n", game->count);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 65363 && moov_player(game, game->map.player.x + 1, game->map.player.y))
		game->map.player.x++;
	else if (keycode == 65361 && moov_player(game, game->map.player.x - 1, game->map.player.y))
		game->map.player.x--;
	else if (keycode == 65364 && moov_player(game, game->map.player.x, game->map.player.y + 1))
		game->map.player.y++;
	else if (keycode == 65362 && moov_player(game, game->map.player.x, game->map.player.y - 1))
		game->map.player.y--;
	draw_all(game);
	return (0);
}
