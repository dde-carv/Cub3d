#ifndef CUB3D_H
# define CUB3D_H

# if defined(__APPLE__) && defined(__MACH__)
#  include "mlx/mlx.h"
# else
#  include "mlx_linux/mlx.h"
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

# include "../libft/inc/libft.h"
# include "structs.h"

/************************* ERROR *************************/

// If there is an error prints the message and exits the program
int		cub_perror(t_error_type err, t_game *g, char *str, int flag);

// Prints message explaining the usage of the program
void	cub_usage(int error);

/************************* MEMORY *************************/

// Frees a pointer
//void	free_pointer(void *str);

// Frees an array
//void	free_array(void **array);

/************************* INIT *************************/


/************************* PARSING *************************/



#endif