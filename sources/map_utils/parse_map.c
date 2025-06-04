#include "cub3d.h"

void	squared_map(t_game *g)
{
	char	**map_square;
	int		i;
	int		j;

	map_square = malloc(sizeof(char *) * (g->height_map + 1));
	j = -1;
	while (++j < g->height_map)
	{
		map_square[j] = malloc(sizeof(char ) * (g->width_map + 1));
		i = -1;
		while (++i < g->width_map)
		{
			if (i >= (int)ft_strlen(g->map[j]))
				map_square[j][i] = ' ';
			else
				map_square[j][i] = g->map[j][i];
		}
		map_square[j][i] = '\0';
	}
	map_square[j] = NULL;
	free_array((void **)g->map);
	g->map = map_square;
}

static void	check_chars(t_game *g, char **map, int i, int j)
{
	if (!g->ply.dir && ft_strchr("NSWE", map[j][i]))
	{
		g->ply.dir = map[j][i];
		g->ply.x = (float)i;
		g->ply.y = (float)j;
	}
	else if (g->ply.dir && ft_strchr("NSWE", map[j][i]))
		cub_perror(inv_ply, g, NULL, 1);
	else if (!ft_strchr("01", map[j][i]))
		cub_perror(inv_char, g, NULL, 1);
	if (j == g->height_map - 1 && !g->ply.dir)
		cub_perror(inv_ply, g, NULL, 1);
}

static void	check_walls(t_game *g, char **map, int i, int j)
{
		if (j - 1 >= 0 && j - 1 < g->height_map)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j - 1]))
			cub_perror(inv_wall, g, NULL, map[j - 1][i] == '0');
	}
	if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, g, NULL, map[j][i - 1] == '0');
	if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j]))
		cub_perror(inv_wall, g, NULL, map[j][i + 1] == '0');
	if (j + 1 >= 0 && j + 1 < g->height_map)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
			cub_perror(inv_wall, g, NULL, map[j + 1][i] == '0');
	}
}

void	check_elements(t_game *g)
{
	int	i;
	int	j;

	j = -1;
	while (++j < g->height_map)
	{
		i = -1;
		while (++i < g->width_map)
		{
			if (g->map[j][i] == ' ')
				check_walls(g, g->map, i, j);
			else
				check_chars(g, g->map, i, j);
		}
	}
}
