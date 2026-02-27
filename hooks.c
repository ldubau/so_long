// header

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free_all(game);
	exit(0);
}
#include <stdio.h>
int	moov_player(t_game *game, int x, int y)
{
	if (game->map.array[y][x] != '1')
	{
		if (game->map.array[y][x] == 'C')
		{
			game->map.array[y][x] = '0';
			game->map.collected++;
		}
		else if (game->map.array[y][x] == 'E')
		{
			if (game->map.collected == game->map.total_collectibles)
				close_game(game);
			else
			{
				// printf("collected = %d\n", game->map.collected);
				// printf("total = %d\n", game->map.total_collectibles);
				return (0);

			}
		}
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit (0);
	else if (keycode == 65363 && moov_player(game, game->map.player.x + 1, game->map.player.y))
		game->map.player.x++;
	else if (keycode == 65361 && moov_player(game, game->map.player.x - 1, game->map.player.y))
		game->map.player.x--;
	else if (keycode == 65364 && moov_player(game, game->map.player.x, game->map.player.y + 1))
		game->map.player.y++;
	else if (keycode == 65362 && moov_player(game, game->map.player.x, game->map.player.y - 1))
		game->map.player.y--;
	draw_all(game);
	return (0);
}
