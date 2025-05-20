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

typedef struct s_textures
{
	int		f_color;
	int		c_color;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
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
	float		x;
	float		y;
	char	dir;
	t_key	keys;
}				t_player;

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
/* 	t_tex		tex;
	t_ray		ray; */
	t_player	pl;
	float		x;
	float		y;
}				t_game;

#endif