/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:37:00 by ldubau            #+#    #+#             */
/*   Updated: 2026/03/05 13:37:09 by ldubau           ###   ########.fr       */
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
	game->player.img = mlx_xpm_file_to_image(game->mlx,
	"./ressources/player.xpm",
	&game->player.width, &game->player.height);
}

void	load_textures(t_game *game)
{
	load_map(game);
	if (!game->wall.img)
			printf("Failed to load wall texture");
	if (!game->floor.img)
		printf("Failed to load floor texture");
	if (!game->collect.img)
		printf("Failed to load collect texture");
	if (!game->exit.img)
		printf("Failed to load exit texture");
	if (!game->player.img)
		printf("Failed to load player texture");
	if (game->wall.width != TILE_SIZE || game->wall.height != TILE_SIZE ||
	game->floor.width != TILE_SIZE || game->floor.height != TILE_SIZE ||
	game->collect.width != TILE_SIZE || game->collect.height != TILE_SIZE ||
	game->exit.width != TILE_SIZE || game->exit.height != TILE_SIZE ||
	game->player.width != TILE_SIZE || game->player.height != TILE_SIZE)
		printf("Wrong texture size");
}
