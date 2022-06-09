/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:49:09 by celadia           #+#    #+#             */
/*   Updated: 2021/10/19 14:53:29 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = -1;
	dest = (unsigned char *)dst;
	while (++i < n)
		dest[i] = (unsigned char)c;
	return (dst);
}
