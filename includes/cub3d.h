#ifndef CUB3D_H
# define CUB3D_H

# if defined(__APPLE__) && defined(__MACH__)
#  include "mlx/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
# endif

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123
#  define RIGHT_KEY				124
#  define UP_KEY				126
#  define DOWN_KEY				125
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53
# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

# ifndef WIN_H
#  define WIN_H 1080
# endif

# ifndef WIN_W
#  define WIN_W 1920
# endif

# ifndef SIZE
#  define SIZE 15
# endif

# include <math.h>
# include "../libft/inc/libft.h"
# include "new_mlx.h"
# include "structs.h"

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
t_game	cub_init(void);

/************************* PARSING *************************/

// Reads file to parse
void	map_read(char *path, t_game *g);

// Squares out the map and fill empty spaces with ' ' for consistency
void	squared_map(t_game *g);

// Preliminary verifications to the map
void	verify_map(t_game *g);

// Checks if the map is valid to play
void	check_elements(t_game *g);

/************************* COLOR *************************/

// Takes the char color and converts into int
int		rgb_atoi(const char *nptr, long *nbr);

/************************* RAYCAST *************************/

void	init_attributes(t_game *g);
void	game_init(t_game *g);
t_vector	ft_newvector(int x, int y);
int		cub_update(void *param);
int		cub_exit(void *param);
void	cub_minimap(t_game *g);
int		get_mini_color(t_game *g, int len, int xy[2]);
void	cub_raycast(t_game *g);
float	distance_to_wall(t_game *g, float ray_angle);
void	cub_miniview(t_game *g);
void	move_pl(int k, t_game *g, float ray_cos, float ray_sin);
float	degree_to_radians(float degree);

#endif