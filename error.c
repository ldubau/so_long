/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:14:44 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/05 10:54:11 by leonpouet        ###   ########.fr       */
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
			while (map->array[i][j])
			{
				if (map->array[i][j] != '1')
					return (0);
				j++;
			}
		else if (map->array[i][0] != '1' || map->array[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>
void	fill(t_map *map, char **cpy_array, int *collec, int *exit, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->width)
		return;
	if (cpy_array[y][x] == '1')
		return;
	if (cpy_array[y][x] == 'C')
		(*collec)++;
	if (cpy_array[y][x] == 'E')
	{
		(*exit)++;
		cpy_array[y][x] = '1';
		return;
	}
	cpy_array[y][x] = '1';
	fill(map, cpy_array, collec, exit, x + 1, y);
	fill(map, cpy_array, collec, exit, x, y + 1);
	fill(map, cpy_array, collec, exit, x - 1, y);
	fill(map, cpy_array, collec, exit, x, y - 1);
	return;
}

int	flood_fill(t_map *map)
{
	int			i;
	int			collec;
	int			exit;
	char		**cpy_array;

	i = 0;
	collec = 0;
	exit = 0;
	cpy_array = ft_split(map->line, '\n');
	if (!cpy_array)
		return (0);
	fill(map, cpy_array, &collec, &exit, map->player.x, map->player.y);
	while (cpy_array[i])
			free(cpy_array[i++]);
		free(cpy_array);
	if (exit < 1 || collec != map->total_collectibles)
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
			return (0);
		i++;
	}
	if (i != game->map.height)
		return (0);
	if (!check_wall(&game->map)) // errormsg
		return (0);
	if (!check_object(&game->map)) // errormsg
		return (0);
	if (!flood_fill(&game->map)) // errormsg
		return (0);
	return (1);
}
