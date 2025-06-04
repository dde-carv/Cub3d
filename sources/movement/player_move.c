#include "cub3d.h"

/* Moves the player forward in the direction they are facing */
static int	move_player_forward(t_game *game)
{
	double	new_x;	// New x position after moving forward
	double	new_y;	// New y position after moving forward

	new_x = game->player.pos_x + game->player.dir_x * MOVESPEED;	// Calculate new x by moving along direction vector
	new_y = game->player.pos_y + game->player.dir_y * MOVESPEED;	// Calculate new y by moving along direction vector
	return (validate_move(game, new_x, new_y));	// Attempt to move, returns 1 if moved, 0 if blocked
}

/* Moves the player backward, opposite to the direction they are facing */
static int	move_player_backward(t_game *game)
{
	double	new_x;	// New x position after moving forward
	double	new_y;	// New y position after moving forward

	new_x = game->player.pos_x - game->player.dir_x * MOVESPEED;	// Subtract direction vector from position
	new_y = game->player.pos_y - game->player.dir_y * MOVESPEED;	// Subtract direction vector from position
	return (validate_move(game, new_x, new_y));	// Attempt to move, returns 1 if moved, 0 if blocked
}

/* Moves the player to the left (strafe), perpendicular to their direction */
static int	move_player_left(t_game *game)
{
	double	new_x;	// New x position after moving forward
	double	new_y;	// New y position after moving forward

	new_x = game->player.pos_x + game->player.dir_y * MOVESPEED;	// Move along the perpendicular vector (dir_y)
	new_y = game->player.pos_y - game->player.dir_x * MOVESPEED;	// Move along the negative perpendicular (dir_x)
	return (validate_move(game, new_x, new_y));	// Attempt to move, returns 1 if moved, 0 if blocked
}

/* Moves the player to the right (strafe), perpendicular to their direction */
static int	move_player_right(t_game *game)
{
	double	new_x;	// New x position after strafing right
	double	new_y;	// New y position after strafing right

	new_x = game->player.pos_x - game->player.dir_y * MOVESPEED;	// Move along the negative perpendicular vector (dir_y)
	new_y = game->player.pos_y + game->player.dir_x * MOVESPEED;	// Move along the perpendicular (dir_x)
	return (validate_move(game, new_x, new_y));	// Attempt to move, returns 1 if moved, 0 if blocked
}

/* Handles all player movement and rotation for the current frame */
int	move_player(t_game *game)
{
	int	moved;	// Tracks if the player has moved or rotated

	moved = 0;
	if (game->player.move_y == 1)
		moved += move_player_forward(game);
	if (game->player.move_y == -1)	// Try to move forward
		moved += move_player_backward(game);
	if (game->player.move_x == -1)	// Try to move backward
		moved += move_player_left(game);
	if (game->player.move_x == 1)	// Try to move left
		moved += move_player_right(game);
	if (game->player.rotate != 0)	// Try to move right
		moved += rotate_player(game, game->player.rotate);	// Rotate player left or right
	return (moved);	// Return if any movement or rotation occurred
}
