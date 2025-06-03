#include "cub3d.h"

// Returns the texture image to use for the current wall hit
t_img	*get_texture(t_game *g)
{
	t_img	*i; // Texture pointer
	float	ray_cos;
	float	ray_sin;

	ray_cos = g->ray.cos;
	if (ray_cos < 0)
		ray_cos = -ray_cos; // Make it positive
	ray_sin = g->ray.sin;
	if (ray_sin < 0)
		ray_sin = -ray_sin; // Make it positive

	i = g->tex.b; // Default to black texture
	// Check which wall was hit and select texture accordingly
	if (g->map[(int)(g->y - ray_sin)][(int)g->x] != '1')
		i = g->tex.no_img; // North wall
	else if (g->map[(int)(g->y + ray_sin)][(int)g->x] != '1')
		i = g->tex.so_img; // South wall
	else if (g->map[(int)g->y][(int)(g->x + ray_cos)] != '1')
		i = g->tex.ea_img; // East wall
	else if (g->map[(int)g->y][(int)(g->x - ray_cos)] != '1')
		i = g->tex.we_img; // West wall
	return (i); // Return selected texture
}

// Gets the color from the texture at a given vertical position z
int	get_tex_color(t_game *g, t_img *i, int z)
{
	int	color; // Color value

	color = 0x00000000; // Default color (black/transparent)
	// Only get color if current map cell is a wall
	if (g->map[(int)g->y][(int)g->x] == '1')
		color = my_mlx_pixel_get(i, (size_t)(i->width * (g->x + g->y)) % i->width, z); // Sample texture
	return (color); // Return color
}

// Draws the wall texture column for a given ray
void	draw_texture(t_game *g, t_img *i, int ray_count, int wall_height)
{
	float	dy;		// Height of each texture pixel on screen
	float	ds;		// Start position for drawing
	float	cy[2];	// cy[0]: current y, cy[1]: start y for this texel
	int		z;		// Texture y coordinate
	int		color;	// Color to draw

	dy = ((float)wall_height * 2) / (float)i->height;	// Calculate step for each texture pixel
	ds = ((float)WIN_H / 2) - (float)wall_height;		// Calculate starting y position
	cy[1] = ds;		// Set initial y position
	z = -1;		// Start at -1 so first increment is 0
	while (++z < i->height)		// For each pixel in texture height
	{
		color = get_tex_color(g, i, z);		// Get color from texture
		color = get_dist_color(color, ds, 0);		// Apply distance shading
		cy[0] = cy[1];		// Start drawing at cy[1]
		while (cy[0] < cy[1] + dy)		// Draw the stretched texel
		{
			if (cy[0] >= 0 && cy[0] < (float)WIN_H)		// Only draw inside window
				my_mlx_pixel_put(&g->win_img, ray_count, cy[0], color);		// Draw pixel
			cy[0]++;		// Move to next y
		}
		cy[1] += dy;		// Move start y for next texel
	}
}

// Draws a vertical column for a ray: ceiling, wall, and floor
void	draw_cub(t_game *g, int ray_count, float dis)
{
	int		wall_height;	// Height of wall slice
	float	ds;				// Start position for wall
	int		j;				// y coordinate

	wall_height = (int)(WIN_H / (1.5 * dis));		// Calculate wall height based on distance
	ds = ((float)WIN_H / 2) - (float)wall_height;		// Calculate where wall starts
	j = -1;
	while (++j < WIN_H)		// For each pixel in column
	{
		if (j < ds)		// Above wall: ceiling
			my_mlx_pixel_put(&g->win_img, ray_count, j, \
				get_dist_color(g->tex.c_color, j, 0));		// Draw ceiling color
		else if (j >= (WIN_H / 2) + wall_height)		// Below wall: floor
			my_mlx_pixel_put(&g->win_img, ray_count, j, \
				get_dist_color(g->tex.f_color, WIN_H - j, 0));		// Draw floor color
	}
	draw_texture(g, get_texture(g), ray_count, wall_height);		// Draw wall texture in the middle
}
