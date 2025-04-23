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

int	main(int argc, char **argv)
{
	t_main	game;

	ft_bzero(&game, sizeof(t_main));
	if (argc == 2)
	{
		game.mlx = mlx_init();
		game.map = map_read(argv[1], &game);
		game.mapcopy = map_read(argv[1], &game);
		if (check_argv(argv[1]) && check_map(&game))
		{
			init_game(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
			print_error("Invalid map.", &game);
	}
	else
		ft_putendl("Bad syntax:\n./cub3D ./maps/<map>.cub.\n");
	return (0);
}
