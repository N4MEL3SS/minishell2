/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:48:45 by celadia           #+#    #+#             */
/*   Updated: 2021/10/16 13:30:15 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*str_end;

	str = (unsigned char *)src;
	str_end = (unsigned char *)(src + n);
	while (str != str_end)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		++str;
	}
	return (NULL);
}
