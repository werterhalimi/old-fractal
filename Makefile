NAME = fractol
LIBFT = libft
MINILIB = minilib
CFLAGS = -Wall -Wextra -Werror -lm -D MAIN
CC = gcc
SRC_PATH = ./
OPTIONS = -I./libft -g3 -fsanitize=address
SRC = main.c julia.c mandelbrot.c fractal.c complex.c input.c window.c color.c burningship.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
			make -C $(LIBFT)
			mv ./libft/libft.a libft.a
			ar rcs libft.a ${OBJS} 

$(MINILIB):
			make -C $(MINILIB)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC)  -Ilibft -Lmlx -lmlx -L. -lft -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) 

unit: 	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) -DUNIT -D UNIT -fsanitize=address -I./libft  -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o unit
clean:	
		rm -f $(OBJS)
		make -C $(LIBFT) clean

fclean:	clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean

re:		fclean all

.PHONY: re fclean clean all $(LIBFT) $(NAME) $(MINILIB)
