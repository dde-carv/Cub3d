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

# define PI						3.14159265358979323846

# ifndef WIN_W
#  define WIN_W 1280
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif

# ifndef SIZE
#  define SIZE 20
# endif

# include <math.h>
# include <limits.h>
# include <float.h>
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

void	init_images(t_game *g);
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
void	init_ray(t_game *g);
int		create_trgb(t_color	rgb);
int		get_dist_color(int color, float ds, int tr);
t_img	*mlx_load_img(void *mlx, char *path);
void	draw_cub(t_game *g, int ray_count, float dis);

void	get_delta_dist(t_game *map);
void	get_step(t_game *map);
void	digital_differential_analyser(t_game *map);
/* Sets color for a pixel at a position in an image */
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

/* Retrieves color as int at given position from an image */
unsigned int	my_mlx_pixel_get(t_img *data, int x, int y);

/* Draws a section of a screen(circle) in a certain color */
void			draw_circle(t_img *img, t_vector center, int radius, int color);

/* Draws a section of a screen in a certain color */
void			my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c);

/* Writes first img to second image to given pos, ignoring "c1" pixels */
void			mlx_img_to_img(int p[2], t_img img[2], int c1);

#endif