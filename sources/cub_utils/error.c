#include "cub3d.h"

int	cub_perror(t_error_type err, t_game *g, char *str, int flag)
{
	if (flag == 0)
		return (0);
	clean_cub(g);
	write(2, "cub3d: ", 7 * (err != end));
	write(2, "invalid number of arguments!\n", 29);
	write(2, "error opening file: ", 20);
	write(2, "invalid file extension!\n", 24);
	write(2, "file is empty!\n", 15);
	write(2, "invalid color!\n", 15);
	write(2, "map is not not closed by walls!\n", 32);
	write(2, "invalid map!\n", 13);
	write(2, "invalid character!\n", 19);
	write(2, "invalid player!\n", 16);
	write(2, "invalid texture!\n", 17);
}
