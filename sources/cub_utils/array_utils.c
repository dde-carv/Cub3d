#include "cub3d.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

char	**ft_extend_array(char **array, char *line)
{
	char	**extended;
	int		len;
	int		i;

	i = -1;
	extended = NULL;
	if (!line)
		return (array);
	len = array_len(array);
	extended = malloc(sizeof(char *) * (len + 2));
	extended[len + 1] = NULL;
	if (!extended)
		return (array);
	while (++i < len)
	{
		extended[i] = ft_strdup(array[i]);
		if (!extended[i])
		{
			free_array((void **)array);
			free_array((void **)extended);
		}
	}
	extended[i] = ft_strdup(line);
	free_array((void **)array);
	return (extended);
}
