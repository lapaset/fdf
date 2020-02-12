# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 15:53:15 by llahti            #+#    #+#              #
#    Updated: 2020/02/06 09:17:52 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
ODIR = objs
SDIR = srcs
INC = includes/
LIB = libft/libft.a
_OBJS = fdf.o make_array.o math_funcs.o key_events.o key_funcs.o\
	key_funcs_move.o mouse_events.o utilities.o iso.o make_grid.o\
	make_image.o get_color.o bresenham.o origami.o flat.o paralinear.o\
	dot_to_image.o draw.o colorthemes.o themes.o
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c
	@[ -d $(ODIR) ] || mkdir $(ODIR)
	@gcc -Wall -Wextra -Werror -c -I $(INC) -o $@ $<

$(NAME): $(OBJS)
	@make -C libft/
	@cc -o $(NAME) $(OBJS) $(LIB) -I /usr/local/include\
		-I /usr/local/lib/ -lmlx\
		-framework OpenGL -framework AppKit
	@echo "\033[1;32mFdF created\033[0m"

clean:
	@rm -Rf $(OBJS)
	@make -C libft/ clean
	@echo "\033[1;32mFdF objects removed\033[0m"

fclean: clean
	@rm -Rf $(NAME)
	@make -C libft/ libclean
	@echo "\033[1;32mFdF removed\033[0m"

re: fclean all

.PHONY: all clean fclean re