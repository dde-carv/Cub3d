#include "cub3d.h"

/* static void	verify_nl(char *line, char *map_temp, t_main *game)
{
	if (line && *line == '\n')
	{
		free(line);
		free(map_temp);
		print_error("Invalid new line in map.", game);
	}
	return ;
} */

char	**map_read(char *path, t_main *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_temp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		//verify_nl(line, map_temp, game);
		if (!line)
			break ;
		tmp = map_temp;
		map_temp = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	map = ft_split(map_temp, '\n');
	free(map_temp);
	close(fd);
	return (map);
}