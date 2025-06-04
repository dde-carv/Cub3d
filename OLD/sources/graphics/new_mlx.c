#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_img *img, t_vector center, int radius, int color)
{
	int	x;
	int	y;

	y = -radius;
	while (++y <= radius)
	{
		x = -radius;
		while (++x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(img, center.x + x, center.y + y, color);
		}
	}
}

void	my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < dim.y)
	{
		x = -1;
		while (++x < dim.x)
			my_mlx_pixel_put(d, p.x + x, p.y + y, c);
	}
}

unsigned int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	mlx_img_to_img(int p[2], t_img img[2], int c1)
{
	int	xy[2];
	int	color;

	xy[1] = -1;
	while (++xy[1] < img[0].height)
	{
		xy[0] = -1;
		while (++xy[0] < img[0].width)
		{
			if (xy[0] + p[0] >= 0 && xy[1] + p[1] >= 0)
			{
				color = my_mlx_pixel_get(&img[0], xy[0], xy[1]);
				if (color != c1)
					my_mlx_pixel_put(&img[1], xy[0] + p[0], \
						xy[1] + p[1], color);
			}
		}
	}
}

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}
