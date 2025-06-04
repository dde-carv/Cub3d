/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:03 by mcombeau          #+#    #+#             */
/*   Updated: 2025/06/04 11:01:12 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(game, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * game->tex.size * game->tex.size);
	if (!buffer)
		clean_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < game->tex.size)
	{
		x = 0;
		while (x < game->tex.size)
		{
			buffer[y * game->tex.size + x]
				= tmp.addr[y * game->tex.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_game *game)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		clean_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	game->textures[NORTH] = xpm_to_img(game, game->tex.north);
	game->textures[SOUTH] = xpm_to_img(game, game->tex.south);
	game->textures[EAST] = xpm_to_img(game, game->tex.east);
	game->textures[WEST] = xpm_to_img(game, game->tex.west);
}

void	init_texinfo(t_tex *textures)
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
