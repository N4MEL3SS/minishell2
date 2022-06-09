#include "libft.h"

int	*ft_mem_alloc(void *ptr, size_t size)
{
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
