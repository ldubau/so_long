// header

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
