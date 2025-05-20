#include "cub3d.h"

static void	get_cf_color(char *text, char *color, t_game *g)
{

}

static void	check_text(char *line, t_game *g)
{
	char	**text;

	text = ft_split(line, ' ');
	if (!text)
		return(free_p(line), cub_perror(no_mem, g, NULL, 1));
	if (!ft_strncmp(text[0], "NO", 3))
		g->tex.no_img = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "SO", 3))
		g->tex.so_img = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "WE", 3))
		g->tex.we_img = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "EA", 3))
		g->tex.ea_img = ft_strdup(text[1]);
	else if (!ft_strncmp(text[0], "F", 2) || !ft_strncmp(text[0], "C", 2))
		get_cf_color(text[0], text[1], g);
	else
		return(free_array(text), cub_perror(inv_map, g, NULL, 1));
}

void	map_read(char *path, t_game *g)
{
	char	*line[2];
	int		text;

	text = -1;
	g->fd = open(path, O_RDONLY);
	cub_perror(inv_file, g, path, g->fd < 0);
	while (1)
	{
		line[0] = get_next_line(g->fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "/n");
		free_p(line[0]);
		if (line[1] && line[1][0] && ++text < 6)
			check_text(line[1], g);
	}

}
