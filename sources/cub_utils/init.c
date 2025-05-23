#include "cub3d.h"

void	init_sprites(t_game *g)
{
	g->win_img.i = NULL;
	g->minimap.i = NULL;
}

static void	init_text(t_game *g)
{
	g->tex.c_color = 0;
	g->tex.f_color = 0;
	g->tex.no_img = NULL;
	g->tex.so_img = NULL;
	g->tex.we_img = NULL;
	g->tex.ea_img = NULL;
}

t_game	cub_init(void)
{
	t_game	g;

	g.mlx = NULL;
	g.win = NULL;
	g.fd = -1;
	g.map = NULL;
	g.height = 0;
	g.width = 0;
	g.ply.dir = 0;
	g.ply.x = -1;
	g.ply.y = -1;
	g.ply.speed = 0.12;
	g.mlx = mlx_init();
	init_text(&g);
	//!! We will add more things to this
	return(g);
}
