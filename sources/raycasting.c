#include "cub3d.h"

float	distance_to_wall(t_game *g, float ray_angle)
{
	(void)ray_angle;
	my_mlx_area_put(&g->minimap, \
		ft_newvector((int)(g->ply.x + 0.5) * SIZE, (int)(g->ply.y + 0.5) * SIZE), \
		ft_newvector(SIZE, SIZE), 0x00FDD663);
	return (0);
}

void	cub_raycast(t_game *g)
{
	float	ray_angle;
	int		ray_count;
	float	dist;

	ray_angle = g->ray.angle - g->ray.hfov;
	ray_count = -1;
	while (++ray_count < WIN_W)
	{
		dist = distance_to_wall(g, ray_angle);
	}
}
