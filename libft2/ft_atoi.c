/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:49:28 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 14:38:09 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	short int			sign;
	unsigned long		result;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '-' && ++str)
		sign = -1;
	else if (*str == '+')
		++str;
	while ('0' <= *str && *str <= '9')
		result = result * 10UL + ((unsigned long)*str++ - 48UL);
	if (result > 9223372036854775807 && sign == 1)
		return (-1);
	if (result > 9223372036854775807 && sign == -1)
		return (0);
	return ((int)result * sign);
}
