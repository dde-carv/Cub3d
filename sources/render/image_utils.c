#include "cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

/* void	set_image_pixel(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_line + x * (image->pixel_bits / 8));
	*(unsigned int *)dst = color;
} */
