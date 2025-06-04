#include "cub3d.h"

int	cub_keyup(int k, t_game *g)
{
	if (k == LEFT_KEY)
		g->ply.keys.left_pressed = 0;
	else if (k == RIGHT_KEY)
		g->ply.keys.right_pressed = 0;
	else if (k == W_KEY)
		g->ply.keys.w_pressed = 0;
	else if (k == A_KEY)
		g->ply.keys.a_pressed = 0;
	else if (k == S_KEY)
		g->ply.keys.s_pressed = 0;
	else if (k == D_KEY)
		g->ply.keys.d_pressed = 0;
	return (0);
}

int	cub_keydown(int k, t_game *g)
{
	if (k == ESC)
		cub_perror(end, g, NULL, 1);
	else if (k == LEFT_KEY)
		g->ply.keys.left_pressed = 1;
	else if (k == RIGHT_KEY)
		g->ply.keys.right_pressed = 1;
	else if (k == W_KEY)
		g->ply.keys.w_pressed = 1;
	else if (k == A_KEY)
		g->ply.keys.a_pressed = 1;
	else if (k == S_KEY)
		g->ply.keys.s_pressed = 1;
	else if (k == D_KEY)
		g->ply.keys.d_pressed = 1;
	return (0);
}

void	init_images(t_game *g)
{
	// window for mlx
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");

	// image for background
	g->win_img.i = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->win_img.addr = mlx_get_data_addr(g->win_img.i, &g->win_img.bpp, \
		&g->win_img.line_len, &g->win_img.endian);

	// image for minimap
	g->minimap.i = mlx_new_image(g->mlx, g->width_map * SIZE, \
		g->height_map * SIZE);
	g->minimap.addr = mlx_get_data_addr(g->minimap.i, &g->minimap.bpp, \
		&g->minimap.line_len, &g->minimap.endian);

	g->minimap.width = g->width_map * SIZE;
	g->minimap.height = g->height_map * SIZE;

	// image for miniview
	g->miniview.i = mlx_new_image(g->mlx, 30 * SIZE, 15 * SIZE);
	g->miniview.addr = mlx_get_data_addr(g->miniview.i, &g->miniview.bpp, \
		&g->miniview.line_len, &g->miniview.endian);

	g->miniview.width = 30 * SIZE;
	g->miniview.height = 15 * SIZE;

}

void	game_init(t_game *g)
{
	init_images(g);
	init_ray(g);
	mlx_hook(g->win, 02, 1L << 0, cub_keydown, g);
	mlx_hook(g->win, 03, 1L << 1, cub_keyup, g);
	mlx_hook(g->win, 17, 0, cub_exit, g);
	mlx_loop_hook(g->mlx, cub_update, g);
	mlx_loop(g->mlx);
}
