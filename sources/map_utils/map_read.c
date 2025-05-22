#include "cub3d.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

char	**ft_extend_array(char **array, char *line)
{
	char	**extended;
	int		len;
	int		i;

	i = -1;
	extended = NULL;
	if (!line)
		return (array);
	len = array_len(array);
	extended = malloc(sizeof(char *) * (len + 2));
	extended[len + 1] = NULL;
	if (!extended)
		return (array);
	while (++i < len)
	{
		extended[i] = ft_strdup(array[i]);
		if (!extended[i])
		{
			free_array((void **)array);
			free_array((void **)extended);
		}
	}
	extended[i] = ft_strdup(line);
	free_array((void **)array);
	return (extended);
}

static int	hex_color()
{
	return(0);
}

static void	get_cf_color(char *text, char *color, t_game *game)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[1]);
	cub_perror(inv_color, game, NULL, (array_len(rgb) != 3));
	cub_perror(inv_color, game, NULL, (r > 255 || g > 255 || \
		b > 255 || r < 0 || g < 0 || b < 0));
	if (ft_strcmp(text, "F") == 0)
		game->tex.f_color = hex_color();
	else if (ft_strcmp(text, "C") == 0)
		game->tex.c_color = hex_color();
}

static void	check_text(char *line, t_game *g)
{
	char	**text;

	text = ft_split(line, ' ');
	if (!text)
		return(free_p(line), cub_perror(no_mem, g, NULL, 1));
	if (!ft_strncmp(text[0], "NO", 3))
		g->tex.no_img = ft_strdup(text[1]); // !!initialize xpm to mlx(watch this with luis) Review this when execution is done
	else if (!ft_strncmp(text[0], "SO", 3))
		g->tex.so_img = ft_strdup(text[1]); // !!initialize xpm to mlx(watch this with luis) Review this when execution is done
	else if (!ft_strncmp(text[0], "WE", 3))
		g->tex.we_img = ft_strdup(text[1]); // !!initialize xpm to mlx(watch this with luis) Review this when execution is done
	else if (!ft_strncmp(text[0], "EA", 3))
		g->tex.ea_img = ft_strdup(text[1]); // !!initialize xpm to mlx(watch this with luis) Review this when execution is done
	else if (!ft_strncmp(text[0], "F", 2) || !ft_strncmp(text[0], "C", 2))
		get_cf_color(text[0], text[1], g);  // !!Review this when execution is done
	else
		return(free_array((void **)text), cub_perror(inv_map, g, NULL, 1));
	free_array((void **)text);
}

int verify_tex(t_game *g)
{
	(void)g;
	return (0);
}

void	map_read(char *path, t_game *g)
{
	char	*line[2];
	int		text;
	//int		flag;

	text = -1;
	g->fd = open(path, O_RDONLY);
	cub_perror(inv_file, g, path, g->fd < 0);
	while (1)
	{
		line[0] = get_next_line(g->fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "\n");
		free_p(line[0]);
		if (line[1] && line[1][0] && ++text < 6)
			check_text(line[1], g);
		else if(line[1] && line[1][0] && text >= 6)
			g->map = ft_extend_array(g->map, line[1]);
		if ((int)ft_strlen(line[1]) > g->width)
			g->width = ft_strlen(line[1]);
		free_p(line[1]);
	}
	g->height = array_len(g->map);
	cub_perror(inv_tex, g, NULL, verify_tex(g));
}
