/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:48:58 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 14:02:30 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)src1 != *(unsigned char *)src2)
			return (*(unsigned char *)src1 - *(unsigned char *)src2);
		++src1;
		++src2;
		--n;
	}
	return (0);
}
