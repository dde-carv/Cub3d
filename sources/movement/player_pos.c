#include "cub3d.h"

static bool	is_valid_pos_wall_collision(t_game *game, double x, double y)
{
	if (game->map.map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_game *game, double x, double y)
{
	if (x < 0.25 || x >= game->map.width - 1.25)
		return (false);
	if (y < 0.25 || y >= game->map.height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_game *game, double x, double y)
{
	if (is_valid_pos_in_map(game, x, y))
		return (true);
	if (is_valid_pos_wall_collision(game, x, y))
		return (true);
	return (false);
}

int	validate_move(t_game *game, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
