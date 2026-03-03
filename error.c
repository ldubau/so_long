/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:14:44 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/03 11:15:57 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		if (i == 0 || i == game->map.height - 1)
			while (game->map.array[i][j])
			{
				if (game->map.array[i][j] != 1)
					return (0);
				j++;
			}
		else
			if (game->map.array[i][0] != 1 || game->map.array[i][game->map.width] != 1)
				return (0);
		i++;
	}
	return (1);
}

void	fill(char **cpy_array, int x, int y)
{
	if (cpy_array[y][x] == '1' || cpy_array[y][x] == 'E')
		return;
	if (cpy_array[y][x] == '0' || cpy_array[y][x] == 'C' || cpy_array[y][x] == 'P')
	{
		cpy_array[y][x] = 'F';
		if (cpy_array[y][x] == 'C')
			collected++;
	}
	fill(cpy_array, x + 1, y);
	fill(cpy_array, x - 1, y);
	fill(cpy_array, x, y + 1);
	fill(cpy_array, x, y - 1);
}

int	flood_fill(t_map *map)
{
	int		i;
	int		j;
	static int		collected;
	char	**cpy_array;

	i = 0;
	collected = 0;
	cpy_array = ft_split(map->line, '\n'); //secu malloc
	if (!cpy_array)
		return (0);
	fill(cpy_array, map->player.x, map->player.y);
	while (cpy_array[i])
	{
		j = 0;
		while (cpy_array[i][j])
			if (cpy_array[i][j++] == 'C')
				return (0);
		i++;
	}
	if (cpy_array[map->exit.y][map->exit.x + 1] == 'F' ||
		cpy_array[map->exit.y][map->exit.x - 1] == 'F' ||
		cpy_array[map->exit.y + 1][map->exit.x] == 'F' ||
		cpy_array[map->exit.y - 1][map->exit.x] == 'F')
		return (1);
	return (0);
}

int	error_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
			j++;
		if (j != game->map.width)
			return (0);
		i++;
	}
	if (i != game->map.height)
		return (0);
	if (!check_wall(game))
		return (0);

	return (1);
}
