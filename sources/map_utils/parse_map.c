#include "cub3d.h"

void	squared_map(t_game *g)
{
	char	**map_square;
	int		i;
	int		j;

	map_square = malloc(sizeof(char *) * (g->height + 1));
	j = -1;
	while (++j < g->height)
	{
		map_square[j] = malloc(sizeof(char ) * (g->width + 1));
		i = -1;
		while (++i < g->width)
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

void	char_map_to_int(t_game *g)
{
	int	**int_map;
	int	i, j;

	int_map = malloc(sizeof(int *) * g->height);
	if (!int_map)
		return ;
	for (i = 0; i < g->height; i++)
	{
		int_map[i] = malloc(sizeof(int) * g->width);
		if (!int_map[i])
			return ; // handle error properly in production code
		for (j = 0; j < g->width; j++)
		{
			if (g->map[i][j] >= '0' && g->map[i][j] <= '9')
				int_map[i][j] = g->map[i][j] - '0';
			else
				int_map[i][j] = -1; // or any value for non-digit chars
		}
	}
	g->map_int = int_map;
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
	if (j == g->height - 1 && !g->ply.dir)
		cub_perror(inv_ply, g, NULL, 1);
}

static void	check_walls(t_game *g, char **map, int i, int j)
{
		if (j - 1 >= 0 && j - 1 < g->height)
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
	if (j + 1 >= 0 && j + 1 < g->height)
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
	while (++j < g->height)
	{
		i = -1;
		while (++i < g->width)
		{
			if (g->map[j][i] == ' ')
				check_walls(g, g->map, i, j);
			else
				check_chars(g, g->map, i, j);
		}
	}
}
