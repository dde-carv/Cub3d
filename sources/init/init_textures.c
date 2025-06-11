/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:24:36 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 10:24:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Loads an XPM image from the given path
and copies its pixel data into a buffer */
static int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(game, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * game->tex.size * game->tex.size);
	if (!buffer)
		cub_perror(no_mem, game, NULL, 1);
	y = -1;
	while (++y < game->tex.size)
	{
		x = -1;
		while (++x < game->tex.size)
		{
			buffer[y * game->tex.size + x]
				= tmp.addr[y * game->tex.size + x];
		}
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}

/* Initializes the textures array by loading all wall textures into memory */
void	init_textures(t_game *game)
{
	game->tex.textures = ft_calloc(5, sizeof * game->tex.textures);
	if (!game->tex.textures)
		cub_perror(no_mem, game, NULL, 1);
	game->tex.textures[NORTH] = xpm_to_img(game, game->tex.north);
	game->tex.textures[SOUTH] = xpm_to_img(game, game->tex.south);
	game->tex.textures[EAST] = xpm_to_img(game, game->tex.east);
	game->tex.textures[WEST] = xpm_to_img(game, game->tex.west);
}

/* Initializes the t_texinfo struct with default values for all fields */
void	init_tex(t_tex *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
