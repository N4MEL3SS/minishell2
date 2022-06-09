/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:49:14 by celadia           #+#    #+#             */
/*   Updated: 2021/10/16 13:30:15 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
