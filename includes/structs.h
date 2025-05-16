
typedef enum	e_error_type
{
	end,
	inv_ac,
	inv_ext,
	inv_file,
	empty_file,
	inv_color,
	inv_wall,
	inv_map,
	inv_char,
	inv_ply,
	inv_tex
}				t_error_type;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	char	**map;
	char	**mapcopy;
	int		n_vc;
	int		n_ve;
	int		n_c;
	int		n_e;
	int		n_p;
	int		moves;
	int		finish;
	int		map_width;
	int		map_height;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		x_pos;
	int		y_pos;
}				t_win;

typedef struct s_key
{

}				t_key;

typedef struct s_textures
{
	int		f_color;
	int		c_color;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
}				t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}				t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**mapcopy;
}				t_game;
