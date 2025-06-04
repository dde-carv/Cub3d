#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_img
{
	void	*i;
	int		height;
	int		width;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

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

typedef struct s_color
{
	long	t;
	long	r;
	long	g;
	long	b;
}				t_color;

typedef struct s_textures
{
	int		f_color;
	int		c_color;
	t_img	*no_img;
	t_img	*so_img;
	t_img	*we_img;
	t_img	*ea_img;
	t_img	*b;
}				t_textures;

typedef struct s_key
{
	int	w_pressed;
	int	a_pressed;
	int	s_pressed;
	int	d_pressed;
	int	left_pressed;
	int	right_pressed;
}				t_key;

typedef struct s_player
{
	char	dir;
	double		x;
	double		y;
	double	speed;
	t_key	keys;
}				t_player;

typedef struct s_ray
{
	double	incre_angle;
	double	angle;
	double	cos;
	double	sin;
	double	hfov;
	double	lim;
	int		precision;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			height_map;
	int			width_map;
	int			fd;
	t_img		win_img;
	t_img		minimap;
	t_img		miniview;
	t_textures	tex;
	t_ray		ray;
	t_player	ply;

	double		dir_x;
    double		dir_y;
	double		x_map;
	double		y_map;
	double		ray_dir_x;
	double		ray_dir_y;
	double		cam_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	double		plane_x;
	double		plane_y;
	int			wall_side;
	double		perpwalldist;

	int			wall_dist;
}				t_game;

#endif