#ifndef CUB3D_H
# define CUB3D_H


# include "../libft/inc/libft.h"
# include "../mlx_linux/mlx.h"
# include "colors.h"
# include "structs.h"
# include <math.h>
# include <float.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define MOVESPEED 0.07
# define ROTSPEED 0.05

/************************* ERROR *************************/

// If there is an error prints the message and exits the program
void	cub_perror(t_error_type err, t_game *g, char *str, int flag);

// Prints message explaining the usage of the program
void	cub_usage(int error);

/************************* MEMORY *************************/

// Frees a pointer
void	free_p(void *str);

// Frees an array
void	free_array(void **array);

// Cleans the game struct
//void	clean_cub(t_game *g);

/************************* INIT *************************/

// Initialize the game struct
void	init_cub(t_game *game);

/************************* PARSING *************************/

// Reads file to parse
void	map_read(char *path, t_game *g);

// Squares out the map and fill empty spaces with ' ' for consistency
void	squared_map(t_game *g);

// Preliminary verifications to the map
void	verify_map(t_game *g);

// Checks if the map is valid to play
void	check_elements(t_game *g);

#endif