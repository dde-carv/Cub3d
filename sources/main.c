#include "cub3d.h"

static int	check_argv(char	*argv)
{
	int	len;

	if (!argv)
		return (0);
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'b' && argv[len - 1] == 'u' && argv[len - 2] == 'c' && \
		argv[len - 3] == '.')
		return (1);
	return (0);
}

static void	check_args(int ac, char **av)
{
	int	i;

	
}

int	main(int ac, char **av)
{
	t_game	g;

	check_args(ac, av);







	ft_bzero(&g, sizeof(t_game));
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
		ft_putendl("Bad syntax:\n./cub3D ./maps/<map>.cub.\n");
	return (0);
}
