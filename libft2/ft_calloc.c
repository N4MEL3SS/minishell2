/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:48:40 by celadia           #+#    #+#             */
/*   Updated: 2021/10/16 13:30:15 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*dst;

	if (len == 0)
		len = 1;
	if (size == 0)
		size = 1;
	dst = malloc(size * len);
	if (!dst)
		return (NULL);
	ft_memset(dst, '\0', size * len);
	return (dst);
}
