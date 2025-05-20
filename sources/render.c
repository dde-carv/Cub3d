#include "cub3d.h"

int	cub_update(void	*param)
{
	t_game	*g;
	g = param;
	
	cub_minimap(g);
	new_mlx_area_put(&g->win_img, ft_newvector(0, 0), ft_newvector(WIN_W, WIN_H), 0xFF4C4C4C);
	mlx_put_image_to_window(g->mlx, g->win, g->win_img.i, 0, 0);
	return (0);
}
