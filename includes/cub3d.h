#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../mlx_linux/mlx.h"
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

/* ---------------------------------------------------------------------------*
							MACROS
 --------------------------------------------------------------------------- */

# define ERR_MALLOC "Could not allocate memory"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define TEX_SIZE 64

# define MOVESPEED 0.07
# define ROTSPEED 0.05


// MINIMAP MACROS
# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

// ERROR MESSAGES
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

/* init/init_data.c */
void	init_data(t_game *data);
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);

#endif