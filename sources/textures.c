/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:37:00 by ldubau            #+#    #+#             */
/*   Updated: 2026/03/06 12:45:03 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"./ressources/wall.xpm",
			&game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"./ressources/floor.xpm",
			&game->floor.width, &game->floor.height);
	game->collect.img = mlx_xpm_file_to_image(game->mlx,
			"./ressources/collect.xpm",
			&game->collect.width, &game->collect.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"./ressources/exit.xpm",
			&game->exit.width, &game->exit.height);
	game->c_exit.img = mlx_xpm_file_to_image(game->mlx,
			"./ressources/closed_exit.xpm",
			&game->c_exit.width, &game->c_exit.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./ressources/player.xpm",
			&game->player.width, &game->player.height);
}

int	load_textures(t_game *game)
{
	load_map(game);
	if (!game->wall.img)
		return (error_message(10));
	if (!game->floor.img)
		return (error_message(11));
	if (!game->collect.img)
		return (error_message(12));
	if (!game->exit.img)
		return (error_message(13));
	if (!game->c_exit.img)
		return (error_message(14));
	if (!game->player.img)
		return (error_message(15));
	if (game->wall.width != TILE_SIZE || game->wall.height != TILE_SIZE
		|| game->floor.width != TILE_SIZE || game->floor.height != TILE_SIZE
		|| game->collect.width != TILE_SIZE || game->collect.height != TILE_SIZE
		|| game->exit.width != TILE_SIZE || game->exit.height != TILE_SIZE
		|| game->c_exit.width != TILE_SIZE || game->c_exit.height != TILE_SIZE
		|| game->player.width != TILE_SIZE || game->player.height != TILE_SIZE)
		return (error_message(16));
	return (1);
}
