#include "cub3d.h"

static void	check_args(int ac, char **av)
{
	int	fd;

	cub_perror(inv_ac, NULL, NULL, ac != 2);
	cub_perror(inv_ac, NULL, NULL, !ft_strrncmp(av[1], "/.cub", 5));
	cub_perror(inv_ext, NULL, NULL, ft_strrncmp(av[1], ".cub", 4));
	fd = open(av[1], O_RDONLY);
	close(fd);
	cub_perror(inv_file, NULL, av[1], fd < 0);
}

int	main(int ac, char **av)
{
	t_game	g;

	check_args(ac, av);
	g = cub_init();
	map_read(av[1], &g);
	squared_map(&g);
	verify_map(&g);
	game_init(&g);
	return (0);
}
