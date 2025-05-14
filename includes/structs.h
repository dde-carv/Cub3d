# include "../libft/inc/libft.h"

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

typedef struct s_player
{

}				t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**mapcopy;
}				t_game;
