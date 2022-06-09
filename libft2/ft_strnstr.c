/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:50:02 by celadia           #+#    #+#             */
/*   Updated: 2021/10/11 18:50:02 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_find(const char *haystack, const char *needle, size_t len)
{
	while (*haystack && *needle && (*haystack == *needle) && len--)
	{
		++haystack;
		++needle;
	}
	if (!*needle)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (ft_find(haystack, needle, len))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}
