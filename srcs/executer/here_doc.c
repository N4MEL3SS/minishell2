#include "minishell.h"

void	remove_redir(t_mini_shell *in, int i)
{
	char	**aux;
	int		j;

	j = 0;
	aux = malloc(sizeof(char *) * (matrix_len(in->split_in) - 1));
	while (in->split_in[j] && j < i)
	{
		aux[j] = ft_strdup(in->split_in[j]);
		j++;
	}
	i += 2;
	while (in->split_in[i])
	{
		aux[j] = ft_strdup(in->split_in[i]);
		in->q_state[j] = in->q_state[i];
		j++;
		i++;
	}
	aux[j] = NULL;
	free_matrix(in->split_in);
	in->split_in = NULL;
	in->split_in = aux;
}

void	here_doc(t_mini_shell *in, int i)
{
	char	*eof;
	int		fd;
	char	*here_doc;

	here_doc = NULL;
	fd = open(".hd_tmp", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		error_msg(in, ERR_FILE, -1, 0);
	eof = ft_strdup(in->split_in[i + 1]);
	while (1)
	{
		here_doc = readline("> ");
		if (!here_doc || !(ft_strcmp(here_doc, eof)))
			break ;
		write(fd, here_doc, ft_strlen(here_doc));
		write(fd, "\n", 1);
		free(here_doc);
	}
	close(fd);
	free(here_doc);
	free(eof);
}

void	exec_hdoc(t_mini_shell *in)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid < 0)
		error_msg(in, ERR_FORK, -1, 0);
	if (!pid)
	{
		signal(SIGINT, handler4);
		while (in->split_in[i])
		{
			if (!(ft_strncmp(in->split_in[i], "<<", 3)) && in->q_state[i] == 0)
				here_doc(in, i);
			i++;
		}
		exit (0);
	}
	waitpid(pid, &in->status, 0);
	g_exit_status = WEXITSTATUS(in->status);
}

int	check_hdoc(t_mini_shell *in)
{
	int	i;

	i = 0;
	in->is_heredoc = 0;
	while (in->split_in[i])
	{
		if (!(ft_strncmp(in->split_in[i], "<<", 3)) && in->q_state[i] == 0)
			in->is_heredoc = 1;
		i++;
	}
	if (in->is_heredoc)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		exec_hdoc(in);
	}
	return (0);
}
