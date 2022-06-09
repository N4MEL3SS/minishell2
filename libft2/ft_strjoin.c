/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:47:44 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 13:47:44 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str_join == NULL)
		return (NULL);
	ft_strlcpy(str_join, s1, s1_len + 1);
	ft_strlcat(str_join, s2, s1_len + s2_len + 1);
	return ((char *)str_join);
}
