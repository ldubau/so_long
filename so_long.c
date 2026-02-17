/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leondubau <leondubau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 08:54:03 by leondubau         #+#    #+#             */
/*   Updated: 2026/02/17 20:40:09 by leondubau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	count_nextline(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (map[i])
		if (map[i++] == '\n' && map[i])
			count++;
	return (count);
}

int	len_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i])
		i ++;
	return (i);
}

char	**map_buid(char *map)
{
	char	**map_tbl;
	int		fd;
	int		i;
	int		length;
	int		width;

	length = count_nextline(map);
	width = len_line(map);
	map_tbl = malloc(length * sizeof(char *) + 1); // peut etre erreur
	fd = open(map, O_RDONLY); // securiser
	i = 0;
	while(i < length)
	{
		map_tbl[i] = ft_calloc(width, sizeof(char) + 1);
		map_tbl[i] = get_next_line(fd);
		map_tbl[i++][length] = '\0';
	}
	map_tbl[i] = NULL;
	close(fd);
	return (map_tbl);
}

int main(int ac, char **av)
{
	char	**map_tbl;

	if (ac != 2)
		return (0); // message d'erreur
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == 0)
		return (0); // message d'erreur
	map_tbl = map_buid(av[1]);

	while (*map_tbl)
	{
		printf("%s\n", *map_tbl);
		map_tbl++;
	}

	return 0;
}
