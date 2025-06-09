#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../mlx_linux/mlx.h"
# include "colors.h"
# include "structs.h"
# include <math.h>
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

/********************************************************/
/*						MACROS							*/
/********************************************************/

# define ERR_MALLOC "Could not allocate memory"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
// # define WIN_WIDTH 960
// # define WIN_HEIGHT 720

# define TEX_SIZE 32

# define MOVESPEED 0.09
# define ROTSPEED 0.06

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

/********************************************************/
/*						FUNCTIONS						*/
/********************************************************/

/************************* INIT *************************/

/* init/init_game.c */
void			init_cub(t_game *game);

/* init/init_game.c */
void			init_img_clean(t_img *img);

/* init/init_game.c */
void			init_ray(t_ray *ray);

/* init/init_mlx.c */
void			init_mlx(t_game *game);

/* init/init_mlx.c */
void			init_img(t_game *game, t_img *image, int width, int height);

/* init/init_mlx.c */
void			init_texture_img(t_game *game, t_img *image, char *path);

/* init/init_textures.c */
void			init_textures(t_game *game);

/* init/init_textures.c */
void			init_tex(t_tex *textures);

/*********************** MOVEMENT ************************/

/* movement/input_handler.c */
void			listen_for_input(t_game *game);

/* movement/player_dir.c */
void			init_player_direction(t_game *game);

/* movement/player_pos.c */
int				validate_move(t_game *game, double new_x, double new_y);

/* movement/player_move.c */
int				move_player(t_game *game);

/* movement/player_rotate.c */
int				rotate_player(t_game *game, double rotdir);

/************************ PARSING ************************/

/* map_utils/map_read.c */
void			map_read(char *path, t_game *g);

/* map_utils/parse_map.c */
char			**squared_map(t_game *g);

/* map_utils/parse_map.c */
void			verify_map(t_game *g);

/* map_utils/parse_map.c */
void			check_elements(t_game *g);

/************************ RENDER *************************/

/* render/render.c */
int				render(t_game *game);

/* render/render.c */
void			render_images(t_game *game);

/* render/raycasting.c */
int				raycasting(t_player *player, t_game *game);

/* render/texture.c */
void			init_texture_pixels(t_game *game);

/* render/texture.c */
void			update_texture_pixels(t_game *game, t_tex *tex, \
				t_ray *ray, int x);

/* render/image_utils.c */
void			set_image_pixel(t_img *image, int x, int y, int color);

/* render/minimap_render.c */
void			render_minimap(t_game *game);

/* render/minimap_image.c */
void			render_minimap_image(t_game *game, t_minimap *minimap);

/************************* ERROR *************************/

/* cub_utils/error.c */
void			cub_perror(t_error_type err, t_game *g, char *str, int flag);

/* cub_utils/error.c */
void			cub_usage(int error);

/* cub_utils/error.c */
int				cub_exit(void *param);

/************************* MEMORY *************************/

/* cub_utils/free.c */
void			free_p(void *str);

/* cub_utils/free.c */
void			free_array(void **array);

/* cub_utils/free.c */
void			clean_cub(t_game *game);

/*********************** UTILS ************************/

/* cub_utils/array_utils.c */
int				array_len(char **array);

/* cub_utils/array_utils.c */
char			**ft_extend_array(char **array, char *line);

/* map_utils/fc_rgb.c */
void			get_cf_color(char **text, t_game *game);

/* map_utils/fc_rgb.c */
unsigned long	convert_rgb_to_hex(int *rgb_tab);

#endif