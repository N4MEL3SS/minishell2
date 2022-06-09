/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:36:16 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/05 16:34:49 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **envp)
{
	t_mini_shell	in;
	t_list			*env_list;

	(void)argv;
	env_list = NULL;
	if (argc == 1)
	{
		init_env_list(&in, &env_list, envp);
		init_structs(&in);
		update_level(&in);
		while (1)
		{
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
			in.status = 0;
			read_input(&in);
			unlink(".hd_tmp");
		}
	}
	return (0);
}
