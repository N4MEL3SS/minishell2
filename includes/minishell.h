/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:03:48 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/06 16:42:11 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> /* printf, perror */
# include <stdlib.h> /* malloc, free, exit, getenv */
# include <errno.h> /* errno */
# include <string.h> /* strerror */
# include <fcntl.h> /* open */
# include <term.h> /* tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
 * tgetstr, tgoto, tputs */
# include <unistd.h> /* write, read, access, close, fork, getcwd, chdir,
 * unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot */
# include <dirent.h> /* opendir, readdir, closedir */
# include <sys/wait.h> /* wait, waitpid, wait3, wait4 */
# include <sys/stat.h> /* stat, lstat, fstat */
# include <sys/ioctl.h> /* ioctl */
# include <signal.h> /* signal, sigaction, sigemptyset, sigaddset, kill */
# include <readline/readline.h> /* readline, rl_clear_history,
 * rl_on_new_line, rl_replace_line, rl_redisplay, add_history */
# include <readline/history.h> /* readline, rl_clear_history,
 * rl_on_new_line, rl_replace_line, rl_redisplay, add_history */
# include <limits.h>

# include "../libft/libft.h"
# include "message.h"

# define R_END 0
# define W_END 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

extern int	g_exit_status;

typedef struct s_arg
{
	int		*quotes;
	char	**arg;
}	t_arg;

typedef struct s_flags
{
	int	i;
	int	j;
	int	start;
	int	count;
	int	count_double;
	int	single_q;
	int	double_q;
	int	global_q;
	int	global_count;
	int	global_sp;
}	t_flags;

typedef struct s_mini_shell
{
	int		fd[2][2];
	int		status;
	int		fd_in;
	int		fd_out;
	int		is_err;
	int		is_infile;
	int		is_outfile;
	int		is_heredoc;
	int		back_stdout;
	int		path_unset;
	int		total_pipes;
	int		*q_state;
	char	*user_in;
	char	*cmd_path;
	char	**split_path;
	char	**split_in;
	char	**dup_env;
	t_list	**env_list;
	t_flags	f;
}	t_mini_shell;

int		main(int argc, char **argv, char **environ);
int		error_msg(t_mini_shell *in, char *MSG, int n, int is_abs);
void	free_list(t_mini_shell *in, t_list *arg_list);
int		char_sp(char c);
char	*ft_getenv(const char *str, t_mini_shell *in);

void	init_env_list(t_mini_shell *in, t_list **envp, char **environ);
void	init_arg_list(t_mini_shell *in);
void	init_structs(t_mini_shell *in);

void	update_env_var(t_mini_shell *in, char *var, char *value);
void	update_level(t_mini_shell *in);

void	read_input(t_mini_shell *in);
void	split_args(t_mini_shell *in);
void	split_tokens(char *s, t_mini_shell *in, int flag);
void	count_tokens(char *s, t_mini_shell *in, int flag);
int		check_args(t_mini_shell *in);

void	expand_vars(t_mini_shell *in);
char	*get_expanded_var(char *str, int i);
void	insert_exp_var(t_mini_shell *in, char **var, char **aux, int j);

void	check_quotes(t_mini_shell *in);
char	**quotes(t_mini_shell *in);
int		quotes_state(t_mini_shell *in, char *str);

int		is_builtin(t_mini_shell *in);
int		is_builtin2(t_mini_shell *in);

void	cd(t_mini_shell *in);
void	echo(t_mini_shell *in);
void	env(t_mini_shell *in, int type);
void	my_exit(t_mini_shell *in);
void	export(t_mini_shell *in);
void	pwd(t_mini_shell *in);
void	unset(t_mini_shell *in, int j);

void	exec_minishell(t_mini_shell *in);
void	exec_absolute(t_mini_shell *in);
void	exec_args(t_mini_shell *in);
void	exec_cmd(t_mini_shell *in);

int		count_pipes(t_mini_shell *in);
void	pipex(t_mini_shell *in, t_list *arg_list);
int		check_error_pipes(t_mini_shell *in);

void	check_redirs(t_mini_shell *in);
int		check_hdoc(t_mini_shell *in);
void	exec_hdoc(t_mini_shell *in);
void	here_doc(t_mini_shell *in, int i);
void	remove_redir(t_mini_shell *in, int i);
void	unset_from_list(t_mini_shell *in, char **var, int size_var);

void	handler(int code);
void	handler2(int code);
void	handler4(int code);


#endif // MINISHELL_H
