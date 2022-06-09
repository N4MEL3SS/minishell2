NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./

SRC =	ft_bzero.c		ft_memchr.c		ft_memcmp.c			\
		ft_memcpy.c		ft_memmove.c	ft_memset.c			\
		ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c		\
        ft_putnbr_fd.c	ft_atoi.c		ft_itoa.c			\
        ft_isalnum.c	ft_isalpha.c	ft_isascii.c		\
        ft_isdigit.c	ft_isprint.c	ft_toupper.c		\
        ft_tolower.c	ft_substr.c		ft_strdup.c			\
        ft_strlcat.c	ft_strlcpy.c	ft_strlen.c			\
        ft_strncmp.c	ft_strnstr.c	ft_split.c			\
        ft_strchr.c		ft_strrchr.c	ft_strtrim.c		\
        ft_strjoin.c	ft_strtrim.c	ft_split.c			\
        ft_striteri.c	ft_strmapi.c	ft_calloc.c

SRC_BONUS = ft_lstnew.c			ft_lstsize.c				\
			ft_lstadd_front.c	ft_lstadd_back.c			\
			ft_lstclear.c		ft_lstdelone.c				\
			ft_lstlast.c		ft_lstiter.c				\
			ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus:	$(OBJ_BONUS)
	@ar rcs	$(NAME) $(OBJ_BONUS)
	@ranlib	$(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
