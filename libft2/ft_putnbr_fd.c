/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:48:42 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 13:48:42 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa_fd(int fd, int n, int num_rank)
{
	char	i;

	if (n < 0)
	{
		write(fd, "-", 1);
		num_rank *= -1;
	}
	while (num_rank != 0)
	{
		i = (char)(n / num_rank + 48);
		write(fd, &i, 1);
		n %= num_rank;
		num_rank /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		num_rank;
	short	num_len;

	num_len = 1;
	num_rank = 1;
	if (n < 0)
		++num_len;
	while (n / num_rank / 10 != 0 && num_len++)
		num_rank *= 10;
	ft_itoa_fd(fd, n, num_rank);
}
