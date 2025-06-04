#include "cub3d.h"

/* Initializes the player's direction and camera plane if facing North or South */
static void	init_player_north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0;			// Set direction vector x-component to 0 (no horizontal movement)
		player->dir_y = 1;			// Set direction vector y-component to 1 (facing down the map)
		player->plane_x = -0.66;	// Set camera plane x-component for FOV (left of direction)
		player->plane_y = 0;		// Set camera plane y-component to 0
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0;			// Set direction vector x-component to 0 (no horizontal movement)
		player->dir_y = -1;			// Set direction vector y-component to -1 (facing up the map)
		player->plane_x = 0.66;		// Set camera plane x-component for FOV (right of direction)
		player->plane_y = 0;		// Set camera plane y-component to 0
	}
	else
		return ;
}

/* Initializes the player's direction and camera plane if facing East or West */
static void	init_player_east_west(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;			// Set direction vector x-component to -1 (facing left on the map)
		player->dir_y = 0;			// Set direction vector y-component to 0
		player->plane_x = 0;		// Set camera plane x-component to 0
		player->plane_y = -0.66;	// Set camera plane y-component for FOV (below direction)
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;			// Set direction vector x-component to 1 (facing right on the map)
		player->dir_y = 0;			// Set direction vector y-component to 0
		player->plane_x = 0;		// Set camera plane x-component to 0
		player->plane_y = 0.66;		// Set camera plane y-component for FOV (above direction)
	}
	else
		return ;
}

/* Initializes the player's direction and camera plane based on their starting direction */
void	init_player_direction(t_game *game)
{
	init_player_north_south(&game->player);
	init_player_east_west(&game->player);
}
