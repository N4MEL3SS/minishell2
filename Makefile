# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celadia <celadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 07:29:28 by celadia           #+#    #+#              #
#    Updated: 2022/05/17 13:54:44 by celadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	PROGRAM_NAMES
NAME = minishell

#	FLAG_COMPILATION
CC = clang
LIBFT = libft/libft.a
LIBFT_DIR = libft
READLINE = -lreadline
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIR)
#-L /Users/celadia/.brew/opt/readline/lib -I /Users/celadia/.brew/opt/readline/include

#	HEADERS
HEADERS_DIR = ./includes/
HEADERS_LIST = 	minishell.h	\
			message.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#	SOURCE
SRCS_CORE = env_ft.c		\
		error_msg.c			\
		init.c				\
		main.c				\
		read_input.c		\
		redirections.c		\
		signal.c			\
		utils.c
SRCS_BUILT = cd.c 			\
		echo.c 				\
		env.c 				\
		exit.c				\
		export.c 			\
		pwd.c 				\
		unset.c
SRCS_EXE = args_list.c 		\
		exec_args.c 		\
		exec_cmd.c 			\
		here_doc.c			\
		pipes.c
SRCS_LEX = check_args.c 	\
		check_error_pipes.c	\
		expand.c 			\
		expand_aux.c 		\
		quotes.c 			\
		split_args.c 		\
		token.c
SRCS_CORE_DIR = ./srcs/core/
SRCS_BUILT_DIR = ./srcs/builtins/
SRCS_EXE_DIR = ./srcs/executer/
SRCS_LEX_DIR = ./srcs/lexer/

#	OBJECT_FILES
OBJS_DIR = ./objs/
OBJS_DIR_NAME = objs
OBJS = $(addprefix $(OBJS_DIR), $(patsubst %.c, %.o, $(SRCS_CORE) $(SRCS_BUILT) $(SRCS_EXE) $(SRCS_LEX)))

#	COLORS
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
END = \033[0m


all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@make -s all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(READLINE) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created. $(END)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR_NAME)
	@echo "$(BLUE) Object files directory was created. $(END)"

$(OBJS_DIR)%.o : $(SRCS_BUILT_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o : $(SRCS_EXE_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o : $(SRCS_LEX_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o : $(SRCS_CORE_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@clear
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(OBJS_DIR)

re: fclean all

.PHONY: all re clean fclean
