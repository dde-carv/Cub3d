#include "cub3d.h"

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
	
	cub_minimap(g);
	cub_miniview(g);

	redraw_elem(g, g->miniview, WIN_W - g->miniview.width - 20, WIN_H - g->miniview.height - 20);

	//my_mlx_area_put(&g->win_img, ft_newvector(0, 0), ft_newvector(WIN_W, WIN_H), 0xFFFFFF);
	mlx_put_image_to_window(g->mlx, g->win, g->win_img.i, 0, 0);
	return (0);
}
