#include "cub3d.h"

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

/* Initializes the t_ray struct to default values for raycasting */
void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;			// Camera plane x-coordinate, used for ray direction calculation
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;			// Step direction in x (either +1 or -1)
	ray->step_y = 0;
	ray->sidedist_x = 0;		// Distance to next x-side
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;		// Distance between x-sides
	ray->deltadist_y = 0;
	ray->wall_dist = 0;			// Perpendicular distance to wall
	ray->wall_hit = 0;			// Exact position of wall hit
	ray->side = 0;				// Was a NS or EW wall hit? (0 or 1)
	ray->line_height = 0;		// Height of line to draw on screen
	ray->draw_start = 0;		// Start pixel for drawing the wall slice
	ray->draw_end = 0;			// End pixel for drawing the wall slice
}

/* Initializes the t_mapinfo struct to default/empty values */
static void	init_map(t_map *map)
{
	map->fd = 0;				// File descriptor for map file (not opened)
	map->line_count = 0;		// Number of lines in the map file
	map->path = NULL;			// Path to the map file, set to NULL
	map->map = NULL;			// Pointer to the map (array of strings), set to NULL
	map->height = 0;			// Height of the map (number of rows)
	map->width = 0;				// Width of the map (number of columns)
	map->index_end_of_map = 0;	// Index of the last line of the map
}

/* Initializes the t_player struct to default/empty values */
static void	init_player(t_player *player)
{
	player->dir = '\0';			// Player's initial direction (N, S, E, W), set to null character
	player->pos_x = 0.0;		// Player's x position in the map
	player->pos_y = 0.0;
	player->dir_x = 0.0;		// Player's direction vector x-component
	player->dir_y = 0.0;
	player->plane_x = 0.0;		// Camera plane x-component (for FOV)
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;			// Movement direction in x (input state)
	player->move_y = 0;
	player->rotate = 0;			// Rotation direction (input state)
}

/* Initializes the main t_game struct and its sub-structs to default values */

void	init_cub(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	init_player(&game->player);
	init_tex(&game->tex);
	init_map(&game->map);
	init_img_clean(&game->minimap);
	game->tex.texture_pixels = NULL;	// Pointer to texture pixel buffers, set to NULL
	game->tex.textures = NULL;			// Pointer to texture arrays, set to NULL
}
