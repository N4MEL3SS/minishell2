#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(src);
	dst = malloc(sizeof(char) * (src_len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, src_len + 1);
	return (dst);
}
