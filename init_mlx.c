//header

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)// plus error
		return;
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long");
	if (!game->win) // plus error
		return;
}
