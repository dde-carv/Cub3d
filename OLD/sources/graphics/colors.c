#include "cub3d.h"

t_color	create_rgbt(int col)
{
	t_color	c;

	c.t = (col >> 24) & 0xFF;
	c.r = (col >> 16) & 0xFF;
	c.g = (col >> 8) & 0xFF;
	c.b = col & 0xFF;
	return (c);
}

int	get_dist_color(int color, float ds, int tr)
{
	t_color	c;
	float	dif;

	if (ds < 0)
		ds = 0;
	dif = powf(1.14, ds / 10);
	c = create_rgbt(color);
	if (tr)
		c.t -= dif;
	else
		c.t = 256;
	c.r -= dif;
	c.g -= dif;
	c.b -= dif;
	if (c. t < 0)
		c.t = 0;
	if (c.r < 0)
		c.r = 0;
	if (c.g < 0)
		c.g = 0;
	if (c.b < 0)
		c.b = 0;
	return (create_trgb(c));
}
