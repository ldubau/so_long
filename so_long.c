/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:38:50 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/03 18:39:18 by leonpouet        ###   ########.fr       */
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

void	parse_object(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] == 'C')
			map->total_collectibles++;
		i++;
	}
	i = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'P')
			{
				map->player.x = j;
				map->player.y = i;
			}
			j++;
		}
		i++;
	}
}

void	map_buid(int fd, t_map *map)
{
	char	*tmp;
	char	*readed_line;

	tmp = NULL;
	readed_line = get_next_line(fd);
	if (!readed_line) //ne stop pas le reste du programme -> valeurs non initialise
		return;
	map->width = ft_strlen(readed_line) - 1;
	map->height = 0;
	map->line = ft_strdup("");
	while (readed_line)
	{
		tmp = ft_strjoin(map->line, readed_line);
		if (!tmp)
			return;
		free(map->line);
		free(readed_line);
		map->line = tmp;
		readed_line = get_next_line(fd);
		map->height++;
	}
	map->array = ft_split(map->line, '\n');
		parse_object(map);
}

int main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		return (0); // message d'erreur
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == 0)
		return (0); // message d'erreur
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ft_bzero(&game, sizeof(t_game));
	map_buid(fd, &game.map);
	if (!error_check(&game))
		return (0);
	close(fd);
	init_mlx(&game);
	load_textures(&game);
	draw_all(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
