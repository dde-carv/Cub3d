#include "cub3d.h"

float	distance_to_wall(t_game *g, float ray_angle)
{
	float	d;

	g->ray.cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
	g->ray.sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
	g->x = g->ply.x + 0.5;
	g->y = g->ply.y + 0.5;
	while (!ft_strchr("1", g->map[(int)g->y][(int)g->x]) && \
		sqrt(powf(g->x - g->ply.x - 0.5, 2.) + \
		powf(g->y - g->ply.y - 0.5, 2.)) < g->ray.lim)
	{
		g->x += g->ray.cos;
		g->y += g->ray.sin;
		if (ft_strchr("1", g->map[(int)g->y][(int)g->x]))
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0xffbd2e);
		else if (ray_angle - 1 < g->ray.angle && ray_angle + 1 > g->ray.angle)
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0xFF0000);
		else
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x879c88);
	}
	draw_circle(&g->minimap,
		ft_newvector(g->ply.x * SIZE + SIZE / 2, g->ply.y * SIZE + SIZE / 2),
		SIZE / 2, 0xFF0000); // circle player in minimap
	d = sqrt(powf(g->x - g->ply.x - 0.5, 2.) + powf(g->y - g->ply.y - 0.5, 2.));
	return (d * cos(degree_to_radians(ray_angle - g->ray.angle)));
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
		cub_draw(g, ray_count, dist);
		ray_angle += g->ray.incre_angle;
	}
}
