#include "cub3d.h"

void	clean_cub(t_game *g)
{
	if (!g)
		return ;
	free_array((void **)g->map);
	if (g->fd > 0)
		close(g->fd);
	destroy_images(g);
	mlx_destroy_display(g->mlx);
	free_p(g->mlx);
}


