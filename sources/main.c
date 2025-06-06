#include "cub3d.h"

static void	check_args(int ac, char **av)
{
	int	fd;

	cub_perror(inv_ac, NULL, NULL, ac != 2);
	cub_perror(inv_file, NULL, NULL, !ft_strrncmp(av[1], "/.cub", 5));
	cub_perror(inv_ext, NULL, NULL, ft_strrncmp(av[1], ".cub", 4));
	fd = open(av[1], O_RDONLY);
	close(fd);
	cub_perror(inv_file, NULL, av[1], fd < 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	check_args(ac, av);
	init_cub(&game);
	init_mlx(&game);
	map_read(av[1], &game);
	game.map.map = squared_map(&game);
	verify_map(&game);
	render_images(&game);
	listen_for_input(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}
