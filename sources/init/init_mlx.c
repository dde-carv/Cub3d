#include "cub3d.h"

void	init_img(t_game *g, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(g->mlx, width, height);
	if (image->img == NULL)
		clean_exit(g, err_msg("mlx", ERR_MLX_IMG, 1));
	image->addr = (int *)mlx_get_g_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_texture_img(t_game *g, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(g->mlx, path, &g->texinfo.size,
			&g->texinfo.size);
	if (image->img == NULL)
		clean_exit(g, err_msg("mlx", ERR_MLX_IMG, 1));
	image->addr = (int *)mlx_get_g_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		clean_exit(g, err_msg("mlx", ERR_MLX_START, 1));
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!g->win)
		clean_exit(g, err_msg("mlx", ERR_MLX_WIN, 1));
	if (BONUS)
		mlx_mouse_move(g->mlx, g->win, g->win_width / 2,
			g->win_height / 2);
	return ;
}