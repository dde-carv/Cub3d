#include "cub3d.h"

void	init_texture_pixels(t_game *game)
{
	int	i;

	if (game->tex.texture_pixels)
		free_array((void **)game->tex.texture_pixels);
	game->tex.texture_pixels = ft_calloc(game->win_height + 1,
			sizeof * game->tex.texture_pixels);
	if (!game->tex.texture_pixels)
		cub_perror(no_mem, game, NULL, 1);
	i = 0;
	while (i < game->win_height)
	{
		game->tex.texture_pixels[i] = ft_calloc(game->win_width + 1,
				sizeof * game->tex.texture_pixels);
		if (!game->tex.texture_pixels[i])
			cub_perror(no_mem, game, NULL, 1);
		i++;
	}
}

static void	get_texture_index(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			game->tex.index = WEST;
		else
			game->tex.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->tex.index = SOUTH;
		else
			game->tex.index = NORTH;
	}
}

void	update_texture_pixels(t_game *game, t_tex *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(game, ray);
	tex->x = (int)(ray->wall_hit * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - game->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = game->tex.textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->tex.texture_pixels[y][x] = color;
		y++;
	}
}
