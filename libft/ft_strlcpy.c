#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	i;

	i = -1;
	src_len = ft_strlen(src);
	if (!dst_size)
		return (src_len);
	while (src[++i] && (i < (dst_size - 1)))
		dst[i] = src[i];
	dst[i] = '\0';
	return (src_len);
}
