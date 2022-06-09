#include "minishell.h"

void	dup_env(t_mini_shell *in, char **envp)
{
	int		i;

	i = -1;
	in->dup_env = NULL;
	if (*envp)
	{
		while (envp[++i] != NULL)
			;
		in->dup_env = (char **)malloc(sizeof(char *) * (i + 1));
		i = -1;
		while (envp[++i])
			in->dup_env[i] = ft_strdup(envp[i]);
		in->dup_env[i] = NULL;
	}
}

void	init_env_list(t_mini_shell *in, t_list **env, char **envp)
{
	int		i;

	i = -1;
	dup_env(in, envp);
	while (in->dup_env[++i] != NULL)
		ft_lstadd_back(env, ft_new_node(in->dup_env[i], \
			ft_strlen(in->dup_env[i]) + 1));
	in->env_list = env;
}

void	init_structs(t_mini_shell *in)
{
	in->user_in = NULL;
	in->split_in = NULL;
	in->cmd_path = NULL;
	in->total_pipes = 0;
	in->fd_in = dup(STDIN);
	in->fd_out = dup(STDOUT);
	in->status = 0;
	g_exit_status = 0;
}
