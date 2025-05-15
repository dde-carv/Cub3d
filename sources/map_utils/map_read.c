#include "cub3d.h"

//* While parsing this function is used to verify the map
static void	verify_l()
{
}

char	**map_read(char *path, t_game *g)
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
		verify_l();
		if (!line)
			break ;
		tmp = map_temp;
		map_temp = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	map = ft_split(map_temp, '\n');
	return (close(fd), free(map_temp), map);
}
