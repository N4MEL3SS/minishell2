#include "libft.h"

char	**matrix_dup(char **matrix)
{
	char	**out;
	int		size;
	int		i;

	i = 0;
	size = matrix_len(matrix);
	out = malloc(sizeof(char *) * (size + 1));
	if (!out)
		return (NULL);
	while (matrix[i])
	{
		out[i] = ft_strdup(matrix[i]);
		if (!out[i])
		{
			free_matrix(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}
