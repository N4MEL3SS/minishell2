/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:37:26 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/01 15:08:37 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv_aux(t_list *aux, char **var)
{
	int	total_size;
	int	size_var;

	size_var = ft_strlen(*var);
	while (aux)
	{
		total_size = ft_strlen(aux->content);
		if (!(ft_strncmp(*var, aux->content, size_var)))
		{
			free(*var);
			return (ft_substr(aux->content, size_var, total_size - size_var));
		}
		aux = aux->next;
	}
	free(*var);
	return (NULL);
}

char	*ft_getenv(const char *str, t_mini_shell *in)
{
	t_list	*aux;
	char	*var;

	aux = *in->env_list;
	var = NULL;
	var = ft_strjoin(str, "=");
	return (ft_getenv_aux(aux, &var));
}

void	update_level(t_mini_shell *in)
{
	int		level;
	char	*number;

	level = ft_atoi(ft_getenv("SHLVL", in));
	if (level < -1)
		level = -1;
	level++;
	number = ft_itoa(level);
	update_env_var(in, "SHLVL=", number);
	free(number);
}
