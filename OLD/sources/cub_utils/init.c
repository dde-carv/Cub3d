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
	g->ray.precision = 100;
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
	g->tex.b = mlx_load_img(g->mlx, "textures/black.xpm");
}

t_game	cub_init(void)
{
	t_game	g;

	g.fd = -1;
	g.map = NULL;
	g.height_map = 0;
	g.width_map = 0;
	g.ply.dir = 0;
	g.ply.x = -1;
	g.ply.y = -1;
	g.ply.speed = 0.12;
	ft_bzero(&g.ply.keys, sizeof(t_key));
	g.mlx = NULL;
	g.win = NULL;
	g.mlx = mlx_init();
	init_text(&g);
	g.ply.x = -1;
	g.ply.y = -1;
	//!! We will add more things to this
	// DDA/raycasting variable initialization
	g.x_map = 0;
	g.y_map = 0;
	g.ray_dir_x = 0;
	g.ray_dir_y = 0;
	g.cam_x = 0;
	g.side_dist_x = 0;
	g.side_dist_y = 0;
	g.delta_dist_x = 0;
	g.delta_dist_y = 0;
	g.step_x = 0;
	g.step_y = 0;
	g.plane_x = 0;
	g.plane_y = 0;
	g.wall_side = 0;
	g.perpwalldist = 0;
	g.wall_dist = 0;
	return(g);
}
