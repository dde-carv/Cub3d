#include "cub3d.h"

int	cub_perror(t_error_type err, t_game *g, char *str, int flag)
{
	(void)g;
	if (flag == 0)
		return (0);
	clean_cub(g);
	write(2, "cub3d: ", 7 * (err != end));
	write(2, "invalid number of arguments!\n", 29 * (err == inv_ac));
	write(2, "invalid file extension!\n", 24 * (err == inv_ext));
	write(2, "error opening file: ", 20 * (err == inv_file));
	write(2, "file is empty!\n", 15 * (err == empty_file));
	write(2, "invalid color!\n", 15 * (err == inv_color));
	write(2, "map is not not closed by walls!\n", 32 * (err == inv_wall));
	write(2, "invalid map!\n", 13 * (err == inv_map));
	write(2, "invalid character!\n", 19 * (err == inv_char));
	write(2, "invalid player!\n", 16 * (err == inv_ply));
	write(2, "invalid texture!\n", 17 * (err == inv_tex));
	ft_putendl_fd(str, 2);
	if ((err == inv_ac) || (err == inv_ext))
	{
		//ft_putchar_fd('\n', 2);
		cub_usage(1);
	}
	if (err == end)
		exit(0);
	exit(1);
	return(1);
}

void	cub_usage(int error)
{
	ft_putstr_fd("Cub3D\nUsage: ./cub3d ./maps/<map_file.cub>\n",2);
	exit(error);
}
