#include "cub3d.h"

static void	cub_init(t_main *g)
{

}

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

int	main(int argc, char **argv)
{
	t_main	g;

	ft_bzero(&g, sizeof(t_main));
	if (argc == 2)
	{
		g.mlx = mlx_init();
		g.map = map_read(argv[1], &g);
		g.mapcopy = map_read(argv[1], &g);
		if (check_argv(argv[1]) && check_map(&g))
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
