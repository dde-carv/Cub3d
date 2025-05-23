#include "cub3d.h"

void	check_move(t_game *g)
{
	/* if (g->ply.keys.left_pressed)
		g->ray.angle -= 3;
	if (g->ply.keys.right_pressed)
		g->ray.angle += 3; */
	if (g->ply.keys.w_pressed)
		move_pl(W_KEY, g, 0, 0);
	if (g->ply.keys.a_pressed)
		move_pl(A_KEY, g, 0, 0);
	if (g->ply.keys.s_pressed)
		move_pl(S_KEY, g, 0, 0);
	if (g->ply.keys.d_pressed)
		move_pl(D_KEY, g, 0, 0);
}

void	redraw_elem(t_game *g, t_img img, int x, int y)
{
	int		p[2];
	t_img	images[2];

	p[0] = x;
	p[1] = y;
	images[0] = img;
	images[1] = g->win_img;
	mlx_img_to_img(p, images, 0xFF000000);
}

int	cub_update(void	*param)
{
	t_game	*g;
	g = param;
	
	check_move(g);

	cub_minimap(g);
	cub_miniview(g);

	my_mlx_area_put(&g->win_img, \
		ft_newvector(0, 0), \
		ft_newvector(WIN_W, WIN_H), 0xD7B076);

	// minimap
	redraw_elem(g, g->minimap, \
		0, 0);

	// miniview
	redraw_elem(g, g->miniview, \
		WIN_W - g->miniview.width - 30,\
		WIN_H - g->miniview.height - 30);

	// Main window
	mlx_put_image_to_window(g->mlx, g->win, g->win_img.i, 0, 0);
	return (0);
}
