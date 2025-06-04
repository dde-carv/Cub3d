#include "cub3d.h"

void	squared_map(t_game *game)
{
	char	**map_square;
	int		i;
	int		j;

	map_square = malloc(sizeof(char *) * (game->map.height + 1));
	j = -1;
	while (++j < game->map.height)
	{
		map_square[j] = malloc(sizeof(char ) * (game->map.width + 1));
		i = -1;
		while (++i < game->map.width)
		{
			if (i >= (int)ft_strlen(game->map.map[j]))
				map_square[j][i] = ' ';
			else
				map_square[j][i] = game->map.map[j][i];
		}
		map_square[j][i] = '\0';
	}
	map_square[j] = NULL;
	free_array((void **)game->map.map);
	game->map.map = map_square;
}

static void	check_chars(t_game *game, char **map, int i, int j)
{
	if (!game->player.dir && ft_strchr("NSWE", map[j][i]))
	{
		game->player.dir = map[j][i];
		game->player.pos_x = (float)i + 0.5;
		game->player.pos_y = (float)j + 0.5;
	}
	else if (game->player.dir && ft_strchr("NSWE", map[j][i]))
		cub_perror(inv_ply, game, NULL, 1);
	else if (!ft_strchr("01", map[j][i]))
		cub_perror(inv_char, game, NULL, 1);
	if (j == game->map.height - 1 && !game->player.dir)
		cub_perror(inv_ply, game, NULL, 1);
}

static void	check_walls(t_game *game, char **map, int i, int j)
{
		if (j - 1 >= 0 && j - 1 < game->map.height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, game, NULL, map[j - 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, game, NULL, map[j - 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, game, NULL, map[j - 1][i] == '0');
	}
	if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, game, NULL, map[j][i - 1] == '0');
	if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, game, NULL, map[j][i + 1] == '0');
	if (j + 1 >= 0 && j + 1 < game->map.height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, game, NULL, map[j + 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, game, NULL, map[j + 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, game, NULL, map[j + 1][i] == '0');
	}
}

void	check_elements(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < game->map.height)
	{
		i = -1;
		while (++i < game->map.width)
		{
			if (game->map.map[j][i] == ' ')
				check_walls(game, game->map.map, i, j);
			else
				check_chars(game, game->map.map, i, j);
		}
	}
}

void	verify_map(t_game *game)
{
	int	i;
	int	j;
	int	w;

	j = -1;
	while (++j < game->map.height)
	{
		w = ft_strlen(game->map.map[j]) -1;
		i = 0;
		while (game->map.map[j][i] == ' ' && i <= w)
			i++;
		while (game->map.map[j][w] == ' ' && w > 0)
			w--;
		if (ft_strncmp(game->map.map[j], "", 1) == 0)
			cub_perror(inv_map, game, NULL, 1);
		if ((j == 0 || j == game->map.height - 1) && ft_strlen(game->map.map[j]) - ft_countchar(game->map.map[j], ' ') - ft_countchar(game->map.map[j], '1'))
			cub_perror(inv_wall, game, NULL, 1);
		else if (w > i && (game->map.map[j][i] != '1' || game->map.map[j][w] != '1'))
			cub_perror(inv_wall, game, NULL, 1);
	}
	check_elements(game);
	cub_perror(inv_map, game, NULL, !j);
	init_player_direction(game);
}
