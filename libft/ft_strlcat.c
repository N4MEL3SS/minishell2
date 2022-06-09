#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	t;

	t = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
	{
		return (src_len + size);
	}
	while ((dst_len + t + 1) < size && src[t] != '\0')
	{
		dst[dst_len + t] = src[t];
		t++;
	}
	dst[dst_len + t] = '\0';
	return (src_len + dst_len);
}
