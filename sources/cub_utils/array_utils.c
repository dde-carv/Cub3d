#include "cub3d.h"

// Returns the number of elements in a NULL-terminated array of strings.
int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

// Extends a NULL-terminated array of strings by adding a new line at the end.
// Frees the old array and returns the new extended array.
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
	if (!extended)
		return (array);
	extended[len + 1] = NULL;
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
	return (free_array((void **)array), extended);
}
