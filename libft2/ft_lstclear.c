/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:49:30 by celadia           #+#    #+#             */
/*   Updated: 2021/10/18 13:49:30 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buff;

	while (*lst)
	{
		if ((*lst)->content)
			del((*lst)->content);
		buff = *lst;
		*lst = buff->next;
		free(buff);
	}
	lst = NULL;
}
