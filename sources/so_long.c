/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:38:50 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/13 13:52:19 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	so_long(t_game *game, char *av)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (error_message(3));
	ft_bzero(game, sizeof(t_game));
	map_buid(fd, &game->map);
	close(fd);
	if (!game->map.array)
	{
		free_all(game);
		return (error_message(11));
	}
	if (!error_check(game))
	{
		free_all(game);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		boolean;

	if (ac != 2)
		return (error_message(1));
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == 0)
		return (error_message(2));
	boolean = so_long(&game, av[1]);
	if (!boolean)
		return (0);
	init_mlx(&game);
	boolean = load_textures(&game);
	if (!boolean)
	{
		close_game(&game);
		return (0);
	}
	draw_all(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
