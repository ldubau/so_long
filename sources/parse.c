/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:59:03 by leonpouet         #+#    #+#             */
/*   Updated: 2026/03/04 09:59:45 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
