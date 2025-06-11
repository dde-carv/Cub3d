/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:25:54 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 10:27:43 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Sets the color of a single pixel in the
// frame image based on the current rendering state
static void	set_frame_image_pixel(t_game *game, t_img *image, int x, int y)
{
	if (game->tex.texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, game->tex.texture_pixels[y][x]);
	else if (y < game->win_height / 2)
		set_image_pixel(image, x, y, game->tex.hex_ceiling);
	else if (y < game->win_height -1)
		set_image_pixel(image, x, y, game->tex.hex_floor);
}

// Renders the entire frame by drawing each pixel to an
// off-screen image, then displaying it
static void	render_frame(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(game, &image, game->win_width, game->win_height);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			set_frame_image_pixel(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

// Performs the raycasting rendering process and draws the frame
void	render_raycast(t_game *game)
{
	init_texture_pixels(game);
	init_ray(&game->ray);
	raycasting(&game->player, game);
	render_frame(game);
}

// Main rendering loop function, called every frame by the MLX loop
int	render(t_game *game)
{
	game->player.has_moved += move_player(game);
	if (game->player.has_moved == 0)
		return (0);
	render_raycast(game);
	return (0);
}
