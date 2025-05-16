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
	fd = open(av[1], O_RDONLY);
	close(fd);
	cub_perror(inv_file, NULL, av[1], fd < 0);
	cub_perror(inv_ext, NULL, NULL, check_argv(av[1]));
}

int	main(int ac, char **av)
{
	t_game	g;

	check_args(ac, av);
	g = cub_init();





	
/* 	ft_bzero(&g, sizeof(t_game));
	if (ac == 2)
	{
		g.mlx = mlx_init();
		g.map = map_read(av[1], &g);
		g.mapcopy = map_read(av[1], &g);
		if (check_argv(av[1]) && check_map(&g))
		{
			init_game(&g);
			gameplay(&g);
			mlx_loop(g.mlx);
		}
		else
			print_error("Invalid map.", &g);
	}
	else
		ft_putendl("Bad syntax:\n./cub3D ./maps/<map>.cub.\n"); */
	return (0);
}
