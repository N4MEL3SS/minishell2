/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:49:04 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 14:21:37 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sour;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (src < dst)
	{
		while (n)
		{
			--n;
			dest[n] = sour[n];
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
