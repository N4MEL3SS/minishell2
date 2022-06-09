/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:46:48 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 13:46:48 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_sub_len;

	if (!str)
		return (NULL);
	if ((size_t)start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len <= ft_strlen(&str[start]))
		s_sub_len = len;
	else
		s_sub_len = ft_strlen(&str[start]);
	sub_str = malloc(sizeof(char) * (s_sub_len + 2));
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, &str[start], s_sub_len + 2);
	return (sub_str);
}
