/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:24:41 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 10:24:42 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Checks if the string contains any digit characters.
static int	no_digit(char *str)
{
	int		i;
	int		digit_not_found;

	i = 0;
	digit_not_found = 42;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			digit_not_found = 0;
		i++;
	}
	return (digit_not_found);
}

// Converts an array of RGB strings to integers, validates them,
// and frees the input array.
static int	*set_rgb_array(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit(rgb_to_convert[i]) == 0)
		{
			free_array((void **)rgb_to_convert);
			free_p(rgb);
			return (0);
		}
	}
	free_array((void **)rgb_to_convert);
	return (rgb);
}

// Splits a line into RGB values, validates, and returns an int array.
static int	*set_rgb_colors(char *line, t_game *game)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		free_array((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		cub_perror(no_mem, game, NULL, 1);
	return (set_rgb_array(rgb_to_convert, rgb));
}

// !!!!!!!!! Review this!!!!!!!!!
// Parses and sets floor or ceiling color from text input.
void	get_cf_color(char **text, t_game *game)
{
	int		fc_flag[2];

	fc_flag[0] = !ft_strcmp(text[0], "F");
	fc_flag[1] = !ft_strcmp(text[0], "C");
	if (fc_flag[0])
		game->tex.floor = set_rgb_colors(text[1], game);
	else if (fc_flag[1])
		game->tex.ceiling = set_rgb_colors(text[1], game);
}

// Converts an array of 3 RGB integers to a single hexadecimal color value.
unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}
