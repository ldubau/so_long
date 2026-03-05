/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:20:06 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/04 10:20:10 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)// plus error
		return;
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long");
	if (!game->win) // plus error
		return;
}
