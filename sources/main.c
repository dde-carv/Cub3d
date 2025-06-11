/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:25:58 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 10:33:50 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Checks the validity of command-line arguments and the input file.
// Exits with an error if the argument count is wrong, the file extension
// is invalid, or the file cannot be opened.
static void	check_args(int ac, char **av)
{
	int	fd;

	cub_perror(inv_ac, NULL, NULL, ac != 2);
	cub_perror(inv_file, NULL, NULL, !ft_strrncmp(av[1], "/.cub", 5));
	cub_perror(inv_file, NULL, NULL, ft_strlen(av[1]) == 4);
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
	render_raycast(&game);
	listen_for_input(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}
