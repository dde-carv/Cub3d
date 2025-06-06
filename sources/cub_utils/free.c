#include "cub3d.h"

void	free_p(void *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free_p(array[i]);
	free(array);
	array = NULL;
}

static void	free_game(t_game *game)
{
	if (game->tex.textures)
		free_array((void **)game->tex.textures);
	if (game->tex.texture_pixels)
		free_array((void **)game->tex.texture_pixels);
	if (game->tex.north)
		free_p(game->tex.north);
	if (game->tex.south)
		free_p(game->tex.south);
	if (game->tex.west)
		free_p(game->tex.west);
	if (game->tex.east)
		free_p(game->tex.east);
	if (game->tex.floor)
		free_p(game->tex.floor);
	if (game->tex.ceiling)
		free_p(game->tex.ceiling);
	if (game->map.fd > 0)
		close(game->map.fd);
	if (game->map.map)
		free_array((void **)game->map.map);
}

void	clean_cub(t_game *game)
{
	if (!game)
		return ;
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_game(game);
}
