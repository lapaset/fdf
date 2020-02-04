# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 15:53:15 by llahti            #+#    #+#              #
#    Updated: 2020/02/04 15:16:00 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = fdf.c make_array.c math_funcs.c key_events.c key_funcs.c key_funcs_move.c \
	mouse_events.c utilities.c iso.c make_grid.c make_image.c get_color.c \
	bresenham.c origami.c flat.c paralinear.c dot_to_image.c draw.c colortest.c
SRCSDIR = $(patsubst %, srcs/%, $(SRCS))
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCS = includes/
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c -Wall -Wextra -Werror -I $(INCS) $(SRCSDIR)
	cc -o $(NAME) $(OBJS) $(LIB) -I /usr/local/include -I /usr/local/lib/ -lmlx\
	 -framework OpenGL -framework AppKit

clean:
	rm -Rf $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -Rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re