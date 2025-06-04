#include "cub3d.h"

static void	set_frame_image_pixel(t_game *game, t_img *image, int x, int y)
{
	if (game->tex.texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, game->tex.texture_pixels[y][x]);
	else if (y < WIN_HEIGHT / 2)
		set_image_pixel(image, x, y, game->tex.hex_ceiling);
	else if (y < WIN_HEIGHT -1)
		set_image_pixel(image, x, y, game->tex.hex_floor);
}

static void	render_frame(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(game, &image, WIN_WIDTH, WIN_HEIGHT);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_frame_image_pixel(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

static void	render_raycast(t_game *game)
{
	init_texture_pixels(game);
	init_ray(&game->ray);
	raycasting(&game->player, game);
	render_frame(game);
}

void	render_images(t_game *game)
{
	render_raycast(game);
	render_minimap(game);
}

int	render(t_game *game)
{
	game->player.has_moved += move_player(game);
	if (game->player.has_moved == 0)
		return (0);
	render_images(game);
	return (0);
}
