/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:03 by mcombeau          #+#    #+#             */
/*   Updated: 2025/06/04 15:12:25 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Loads an XPM image from the given path
and copies its pixel data into a buffer */
static int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp; // Temporary image struct to hold the loaded XPM image
	int		*buffer; // Buffer to store the pixel data as integers
	int		x; // Loop variable for columns
	int		y; // Loop variable for rows

	init_texture_img(game, &tmp, path); // Load the XPM image into tmp using MLX and set up its metadata
	buffer = ft_calloc(1, sizeof * buffer * game->tex.size * game->tex.size); // Allocate memory for the pixel buffer (size x size)
	if (!buffer)
		clean_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	y = -1;
	while (++y < game->tex.size) // For each row in the image
	{
		x = -1;
		while (++x < game->tex.size) // For each column in the image
		{
			buffer[y * game->tex.size + x]
				= tmp.addr[y * game->tex.size + x]; // Copy the pixel value from the image to the buffer
		}
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}

/* Initializes the textures array by loading all wall textures into memory */
void	init_textures(t_game *game)
{
	game->tex.textures = ft_calloc(5, sizeof * game->tex.textures); // Allocate space for 5 texture pointers (N, S, E, W, plus one extra)
	if (!game->tex.textures)
		clean_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	game->tex.textures[NORTH] = xpm_to_img(game, game->tex.north);
	game->tex.textures[SOUTH] = xpm_to_img(game, game->tex.south);
	game->tex.textures[EAST] = xpm_to_img(game, game->tex.east);
	game->tex.textures[WEST] = xpm_to_img(game, game->tex.west);
}

/* Initializes the t_texinfo struct with default values for all fields */
void	init_texinfo(t_tex *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;		// Floor color as hex value, set to 0
	textures->hex_ceiling = 0x0;	// Ceiling color as hex value, set to 0
	textures->size = TEX_SIZE;		// Texture size (width/height), set to TEX_SIZE macro
	textures->step = 0.0;			// Step value for texture mapping, set to 0.0
	textures->pos = 0.0;			// Position value for texture mapping, set to 0.0
	textures->x = 0;				// Texture x-coordinate, set to 0
	textures->y = 0;				// Texture y-coordinate, set to 0
}
