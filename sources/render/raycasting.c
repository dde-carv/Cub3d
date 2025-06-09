#include "cub3d.h"

/*
We initialize the set up for the rays
- camera_x -> Where is the camera (-1 = left, 0 = center, 1 = right)
- dir_x/y = direction of the ray
- map_x/y = current square of the ray
- deltadist_x/y = distance to go to the next x or y.
*/

// Initialize ray info for a given screen column x
static void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	// Calculate camera_x: -1 (left) to 1 (right) across the screen
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;

	// Calculate ray direction vector for this column
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;

	// Which box of the map we're in
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;

	// Length of ray from one x or y-side to next x or y-side
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

/*
- We are doing the initial set up for the dda
- dda algorithm will jump one square in each loop eiter in a x or y direction
- ray->sidedist_x or y = distance from the ray start position to the
	next x or y position
- if x or y < 0 go the next x or y to the left
- if x or y > 0 go the next x or y to the right
*/

// Set up DDA (Digital Differential Analyzer) step and initial side distances
static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1; // Step left
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1; // Step right
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1; // Step up
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1; // Step down
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/

// Perform DDA: step through the map until a wall is hit
static void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		// Jump to next map square, either in x or y direction
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // Hit a vertical wall
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // Hit a horizontal wall
		}
		// Check if ray is outside map bounds
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > game->map.height - 0.25
			|| ray->map_x > game->map.width - 1.25)
			break ;
		// Check if ray has hit a wall (map value > '0')
		else if (game->map.map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

// Calculate wall distance and line height for drawing
static void	calculate_line_height(t_ray *ray, t_game *game, t_player *player)
{
	// Calculate distance to wall
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	
	// Calculate height of line to draw on screen
	ray->line_height = (int)(game->win_height / ray->wall_dist);

	// Calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = -(ray->line_height) / 2 + game->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->win_height / 2;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
	
	// Calculate exact position of wall hit (for texture mapping)
	if (ray->side == 0)
		ray->wall_hit = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_hit -= floor(ray->wall_hit); // Only the fractional part
}

// Main raycasting loop: cast one ray per screen column
int	raycasting(t_player *player, t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < game->win_width)
	{
		init_raycasting_info(x, &ray, player);	// Set up ray for this column
		set_dda(&ray, player);					// Set up DDA stepping
		perform_dda(game, &ray);				// Step through map to find wall
		calculate_line_height(&ray, game, player);	// Compute wall height, etc.
		update_texture_pixels(game, &game->tex, &ray, x);	// Draw the column
		x++;
	}
	return (SUCCESS);
}
