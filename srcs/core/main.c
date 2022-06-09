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
