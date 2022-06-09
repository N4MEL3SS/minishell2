cmake_minimum_required(VERSION 3.21)
project(minishell_ncallie_cmake C)

add_compile_options(-Wall -Wextra -Werror)
set(CMAKE_C_STANDARD 99)

include_directories(includes/)
include_directories(libft/)

set(HEAD includes/minishell.h includes/message.h)
set(LIBFT_HEAD)

set(SRC_CORE srcs/core/main.c
		srcs/core/error_msg.c
		srcs/core/read_input.c
		srcs/core/redirections.c
		srcs/core/signal.c srcs/core/utils.c srcs/core/init.c)

set(SRC_BUILTINS srcs/builtins/cd.c
		srcs/builtins/echo.c
		srcs/builtins/env.c
		srcs/core/env_ft.c
		srcs/builtins/exit.c
		srcs/builtins/export.c
		srcs/builtins/pwd.c
		srcs/builtins/unset.c)

set(SRC_EXECUTER srcs/executer/args_list.c
		srcs/executer/exec_args.c
		srcs/executer/exec_cmd.c
		srcs/executer/here_doc.c
		srcs/executer/pipes.c)

set(SRC_LEXER srcs/lexer/check_args.c
		srcs/lexer/check_error_pipes.c
		srcs/lexer/expand.c
		srcs/lexer/expand_aux.c
		srcs/lexer/quotes.c
		srcs/lexer/split_args.c
		srcs/lexer/token.c)

set(LIBFT libft/del_str_pos.c
		libft/free_matrix.c
		libft/ft_atoi.c
		libft/ft_bzero.c
		libft/ft_isalnum.c
		libft/ft_isalpha.c
		libft/ft_isdigit.c
		libft/ft_itoa.c
		libft/ft_lst_free.c
		libft/ft_lst_sort.c
		libft/ft_lstadd_back.c
		libft/ft_lstclear.c
		libft/ft_lstdelone.c
		libft/ft_lstdup.c
		libft/ft_lstnew.c
		libft/ft_lstsize.c
		libft/ft_memcpy.c
		libft/ft_new_node.c
		libft/ft_putchar_fd.c
		libft/ft_putendl_fd.c
		libft/ft_putstr_fd.c
		libft/ft_split.c
		libft/ft_strchr.c
		libft/ft_strcmp.c
		libft/ft_strdup.c
		libft/ft_strjoin.c
		libft/ft_strjoin3.c
		libft/ft_strlcat.c
		libft/ft_strlcpy.c
		libft/ft_strlen.c
		libft/ft_strncmp.c
		libft/ft_substr.c
		libft/list_to_matrix.c
		libft/matrix_dup.c
		libft/matrix_len.c
		libft/ft_mem_alloc.c
		libft/ft_lstlast.c)

add_executable(minishell ${HEAD} ${SRC_CORE} ${SRC_BUILTINS} ${SRC_EXECUTER} ${SRC_LEXER} ${LIBFT_HEAD} ${LIBFT})
target_link_libraries(minishell readline)
