/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:14:44 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/06 08:18:51 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_object(t_map *map)
{
	int	i;
	int	j;
	int	exit_player;
	int	collect;

	i = 0;
	exit_player = 0;
	collect = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'E' || map->array[i][j] == 'P')
				exit_player++;
			if (map->array[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (exit_player != 2 || collect < 1)
		return (0);
	return (1);
}

int	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		if (i == 0 || i == map->height - 1)
		{
			while (map->array[i][j])
			{
				if (map->array[i][j] != '1')
					return (0);
				j++;
			}
		}
		else if (map->array[i][0] != '1' ||
		map->array[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	fill(t_map *map, char **cpy_array, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->width)
		return ;
	if (cpy_array[y][x] == '1')
		return ;
	if (cpy_array[y][x] == 'C')
		map->filled_collect++;
	if (cpy_array[y][x] == 'E')
	{
		map->filled_exit++;
		cpy_array[y][x] = '1';
		return ;
	}
	cpy_array[y][x] = '1';
	fill(map, cpy_array, x + 1, y);
	fill(map, cpy_array, x, y + 1);
	fill(map, cpy_array, x - 1, y);
	fill(map, cpy_array, x, y - 1);
	return ;
}

int	flood_fill(t_map *map)
{
	int			i;
	char		**cpy_array;

	i = 0;
	cpy_array = ft_split(map->line, '\n');
	if (!cpy_array)
		return (0);
	fill(map, cpy_array, map->player.x, map->player.y);
	while (cpy_array[i])
		free(cpy_array[i++]);
	free(cpy_array);
	if (map->filled_exit < 1 || map->filled_collect != map->total_collectibles)
		return (0);
	return (1);
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
			return (error_message(4));
		i++;
	}
	if (i != game->map.height)
		return (error_message(4));
	if (!check_wall(&game->map))
		return (error_message(5));
	if (!check_object(&game->map))
		return (error_message(6));
	if (!flood_fill(&game->map))
		return (error_message(7));
	return (1);
}
