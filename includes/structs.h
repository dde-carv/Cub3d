#ifndef STRUCTS_H
# define STRUCTS_H

enum e_output
{
	SUCCESS,
	FAILURE,
	ERR,
	BREAK,
	CONTINUE
};

enum e_texture_index
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef enum	e_error_type
{
	end,
	inv_ac,
	inv_ext,
	inv_file,
	empty_file,
	no_mem,
	inv_color,
	inv_wall,
	inv_map,
	inv_char,
	inv_ply,
	inv_tex
}				t_error_type;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_tex
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
	int				**texture_pixels;
	int				**textures;
}	t_tex;

typedef struct s_minimap
{
	char	**map;
	t_img	*img;
	int		size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
}	t_minimap;

typedef struct s_map
{
	int			fd;
	int			line_count;
	char		*path;
	char		**map;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_map;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_map		map;
	t_img		minimap;
	t_player	player;
	t_ray		ray;
	t_tex		tex;
}	t_game;

#endif