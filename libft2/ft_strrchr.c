/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:50:08 by celadia           #+#    #+#             */
/*   Updated: 2021/10/19 15:44:48 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[i]);
	while (i-- && str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}
