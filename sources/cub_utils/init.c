#include "cub3d.h"

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
	g.ply.speed = 0.12;
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
