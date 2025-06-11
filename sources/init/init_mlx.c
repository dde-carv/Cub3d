/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:24:34 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 10:27:13 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes a t_img struct as a new blank image with given width and height
void	init_img(t_game *game, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		cub_perror(no_mem, game, NULL, 1);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

// Initializes a t_img struct from an XPM file at the given path
void	init_texture_img(t_game *game, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->tex.size,
			&game->tex.size);
	if (image->img == NULL)
		cub_perror(inv_tex, game, NULL, 1);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

// Initializes the MLX context and window for the application
void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		cub_perror(no_mem, game, NULL, 1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		cub_perror(no_mem, game, NULL, 1);
	return ;
}
