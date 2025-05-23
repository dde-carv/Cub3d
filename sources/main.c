#include "cub3d.h"

static int	check_argv(char	*argv)
{
	int	len;

	if (!argv)
		return (1);
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'b' && argv[len - 1] == 'u' && argv[len - 2] == 'c' && \
		argv[len - 3] == '.')
		return (0);
	return (1);
}

static void	check_args(int ac, char **av)
{
	int	fd;

	cub_perror(inv_ac, NULL, NULL, ac != 2);
	cub_perror(inv_ext, NULL, NULL, check_argv(av[1]));
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
