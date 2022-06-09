/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:48:07 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 15:11:57 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_split_clear(char **split_str)
{
	int	i;

	i = -1;
	while (*split_str && split_str[++i] != NULL)
		free(split_str[i]);
	free(split_str);
	return (NULL);
}

size_t	ft_count_words(const char *str, char c)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		while (*str == c)
			++str;
		if (*str && ++words)
			while (*str && *str != c)
				++str;
	}
	return (words);
}

size_t	ft_word_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

void	*ft_split_words(char **split_str, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	start;
	size_t	word_len;

	i = -1;
	start = 0;
	while (++i < words)
	{
		while (s[start] == c)
			++start;
		word_len = ft_word_len(&s[start], c);
		split_str[i] = ft_substr(s, start, word_len);
		if (!split_str[i])
			return (ft_split_clear(split_str));
		start += word_len;
	}
	split_str[i] = NULL;
	return (split_str);
}

char	**ft_split(char const *str, char c)
{
	char	**split_str;
	size_t	words;

	if (!str)
		return (NULL);
	words = ft_count_words(str, c);
	split_str = malloc(sizeof(char *) * (words + 1));
	if (!split_str)
		return (NULL);
	return (ft_split_words(split_str, str, c, words));
}
