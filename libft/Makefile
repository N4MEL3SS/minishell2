# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncallie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 14:39:54 by ncallie           #+#    #+#              #
#    Updated: 2022/03/01 15:01:06 by ncallie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RM = rm -f
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_lstlast.c 				\
		 ft_strlen.c ft_strchr.c ft_strncmp.c ft_strlcat.c 				\
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c 				\
		 ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c 				\
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_split.c 		\
		 ft_lstnew.c  ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c 		\
		 ft_lstclear.c  ft_new_node.c ft_strcmp.c ft_lstdup.c 			\
		 ft_matrix_free.c ft_strjoin3.c ft_lstmatrix.c ft_matrix_len.c 	\
		 ft_matrix_dup.c ft_del_str_pos.c ft_lstsort.c ft_lstfree.c

#	COLORS
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
END = \033[0m

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created.$(END)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
