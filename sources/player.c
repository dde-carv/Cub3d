#include "cub3d.h"

void	move_pl(int k, t_game *g, float ray_cos, float ray_sin)
{
	float	angle;

	angle = g->ray.angle;
	if (k == W_KEY)
		angle = g->ray.angle - 90;
	else if (k == A_KEY)
		angle = g->ray.angle - 180;
	else if (k == S_KEY)
		angle = g->ray.angle + 90;
	ray_cos = cos(degree_to_radians(angle)) * g->ply.speed;
	ray_sin = sin(degree_to_radians(angle)) * g->ply.speed;
	if (!ft_strchr("1c", g->map[(int)(g->ply.y + 0.5 + \
			(3 * ray_sin))][(int)(g->ply.x + 0.5)]))
		g->ply.y += ray_sin;
	if (!ft_strchr("1c", \
		g->map[(int)(g->ply.y + 0.5)][(int)(g->ply.x + 0.5 + (3 * ray_cos))]))
		g->ply.x += ray_cos;
}
