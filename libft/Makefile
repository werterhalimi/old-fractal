SRCS = ft_putnbr_fd.c ft_striteri.c ft_split.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strmapi.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_calloc.c ft_substr.c ft_strdup.c ft_strnstr.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strncmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

BSRCS = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c

BOBJS = ${BSRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:		fclean all

bonus:		${NAME} ${BOBJS}
			ar rc ${NAME} ${OBJS} ${BOBJS}

.PHONY: all clean fclean re bonus
