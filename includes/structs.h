#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}			t_img;



#endif