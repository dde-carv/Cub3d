#ifndef STRUCTS_H
# define STRUCTS_H

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
	float		x;
	float		y;
	float	speed;
	t_key	keys;
}				t_player;

typedef struct s_ray
{
	float	incre_angle;
	float	angle;
	float	cos;
	float	sin;
	float	hfov;
	float	lim;
	int		precision;
}				t_ray;

typedef struct s_game
{
	int			fd;
	char		**map;
	int			height;
	int			width;
	int			mouse_x;
	int			rate;
	int			neg;
	long		nframes;
	void		*mlx;
	void		*win;
	t_img		win_img;
	t_img		win_g;
	t_img		win_r;
	t_img		minimap;
	t_img		miniview;
	t_textures	tex;
	t_ray		ray;
	t_player	ply;
	float		x;
	float		y;
}				t_game;

#endif