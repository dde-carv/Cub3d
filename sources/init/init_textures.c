/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:03 by mcombeau          #+#    #+#             */
/*   Updated: 2025/06/04 09:45:20 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_game *g, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(g, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * g->texinfo.size * g->texinfo.size);
	if (!buffer)
		clean_exit(g, err_msg(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < g->texinfo.size)
	{
		x = 0;
		while (x < g->texinfo.size)
		{
			buffer[y * g->texinfo.size + x]
				= tmp.addr[y * g->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(g->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_game *g)
{
	g->textures = ft_calloc(5, sizeof * g->textures);
	if (!g->textures)
		clean_exit(g, err_msg(NULL, ERR_MALLOC, 1));
	g->textures[NORTH] = xpm_to_img(g, g->texinfo.north);
	g->textures[SOUTH] = xpm_to_img(g, g->texinfo.south);
	g->textures[EAST] = xpm_to_img(g, g->texinfo.east);
	g->textures[WEST] = xpm_to_img(g, g->texinfo.west);
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
