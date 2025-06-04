#include "cub3d.h"

static int	check_valid_rgb(int *rgb, t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (cub_perror(inv_color, game, NULL, 1), 1);
		i++;
	}
	return (0);
}

static int verify_color(t_game *game)
{
	if (!game->tex.floor || !game->tex.ceiling || check_valid_rgb(game->tex.floor, game) || check_valid_rgb(game->tex.ceiling, game))
		return(1);
	game->tex.hex_ceiling = convert_rgb_to_hex(game->tex.ceiling);
	game->tex.hex_floor = convert_rgb_to_hex(game->tex.floor);
	return (0);
}

static int verify_tex(t_game *game)
{
	if (!game->tex.north || !game->tex.south || !game->tex.west || !game->tex.east)
		return(1);
	return (0);
}

// !!!!!!!!! Review this  !!!!!!!!!
static void	check_text(char *line, t_game *game)
{
	char	**text;

	text = ft_split(line, ' ');
	if (!text)
		return(free_p(line), cub_perror(no_mem, game, NULL, 1));
	if (!text[0] || array_len(text) != 2)
		return(free_array((void **)text), cub_perror(inv_tex, game, NULL, 1));
	if (!ft_strncmp(text[0], "NO", 3))
		game->tex.north = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "SO", 3))
		game->tex.south = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "WE", 3))
		game->tex.west = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "EA", 3))
		game->tex.east = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "F", 2) || !ft_strncmp(text[0], "C", 2))
		get_cf_color(text, game);		//!! Review this
	else
		return(free_array((void **)text), cub_perror(inv_map, game, NULL, 1));
	free_array((void **)text);
}

void	map_read(char *path, t_game *game)
{
	char	*line[2];
	int		text;

	text = -1;
	game->map.fd = open(path, O_RDONLY);
	cub_perror(inv_file, game, path, game->map.fd < 0);
	while (1)
	{
		line[0] = get_next_line(game->map.fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "\n");
		free_p(line[0]);
		if (line[1] && line[1][0] && ++text < 6)
			check_text(line[1], game);		// !!!!!!!!! Review this !!!!!!!!!
		else if(line[1] && line[1][0] && text >= 6)
			game->map.map = ft_extend_array(game->map.map, line[1]);
		if ((int)ft_strlen(line[1]) > game->map.width)
			game->map.width = ft_strlen(line[1]);
		free_p(line[1]);
	}
	game->map.height = array_len(game->map.map);
	cub_perror(inv_tex, game, NULL, verify_tex(game));	// !!!!!!!!! Review this !!!!!!!!!
	cub_perror(inv_tex, game, NULL, verify_color(game));	// !!!!!!!!! Review this !!!!!!!!!
	init_textures(game);
}

