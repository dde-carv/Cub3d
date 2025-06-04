#include "cub3d.h"

void	free_p(void *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free_p(array[i]);
	free(array);
	array = NULL;
}

void	clean_cub(t_game *g)
{
	(void)g;
}
