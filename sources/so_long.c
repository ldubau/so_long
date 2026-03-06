/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:38:50 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/06 08:28:26 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h> //no

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.array)
	{
		while (game->map.array[i])
			free(game->map.array[i++]);
		free(game->map.array);
	}
	if (game->map.line)
		free(game->map.line);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		return (error_message(1));
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == 0)
		return (error_message(2));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_message(3));
	ft_bzero(&game, sizeof(t_game));
	map_buid(fd, &game.map);
	if (!error_check(&game))
	{
		free_all(&game);
		return (0);
	}
	close(fd);
	init_mlx(&game);
	load_textures(&game);
	draw_all(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
