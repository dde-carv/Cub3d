#include "cub3d.h"

void	init_ray(t_game *g)
{
	g->ray.angle = 0;
	if (g->ply.dir == 'S')
		g->ray.angle = 90;
	else if (g->ply.dir == 'W')
		g->ray.angle = 180;
	else if (g->ply.dir == 'N')
		g->ray.angle = 270;
	g->ray.hfov = 30;
	g->ray.incre_angle = 2 * g->ray.hfov / WIN_W;
	g->ray.precision = 50;
	g->ray.lim = 11;
}

static void	init_text(t_game *g)
{
	g->win_img.i = NULL;
	g->minimap.i = NULL;
	g->miniview.i = NULL;
	g->tex.c_color = -1;
	g->tex.f_color = -1;
	g->tex.no_img = NULL;
	g->tex.so_img = NULL;
	g->tex.we_img = NULL;
	g->tex.ea_img = NULL;
}

t_game	cub_init(void)
{
	t_game	g;

	g.fd = -1;
	g.map = NULL;
	g.height = 0;
	g.width = 0;
	g.ply.dir = 0;
	g.ply.x = -1;
	g.ply.y = -1;
	g.ply.speed = 0.2;
	g.mlx = NULL;
	g.win = NULL;
	g.mlx = mlx_init();
	init_text(&g);
	g.ply.x = -1;
	g.ply.y = -1;
	ft_bzero(&g.ply.keys, sizeof(t_key));
	//!! We will add more things to this
	return(g);
}
