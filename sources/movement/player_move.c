/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:25:00 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 10:25:01 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Moves the player forward in the direction they are facing */
static int	move_player_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVESPEED;
	return (validate_move(game, new_x, new_y));
}

/* Moves the player backward, opposite to the direction they are facing */
static int	move_player_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVESPEED;
	return (validate_move(game, new_x, new_y));
}

/* Moves the player to the left (strafe), perpendicular to their direction */
static int	move_player_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_x * MOVESPEED;
	return (validate_move(game, new_x, new_y));
}

/* Moves the player to the right (strafe), perpendicular to their direction */
static int	move_player_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_x * MOVESPEED;
	return (validate_move(game, new_x, new_y));
}

/* Handles all player movement and rotation for the current frame */
int	move_player(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_y == 1)
		moved += move_player_forward(game);
	if (game->player.move_y == -1)
		moved += move_player_backward(game);
	if (game->player.move_x == -1)
		moved += move_player_left(game);
	if (game->player.move_x == 1)
		moved += move_player_right(game);
	if (game->player.rotate != 0)
		moved += rotate_player(game, game->player.rotate);
	return (moved);
}
