# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 16:29:38 by llahti            #+#    #+#              #
#    Updated: 2020/01/28 11:59:55 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c ft_islower.c\
ft_isupper.c ft_memalloc.c ft_memdel.c ft_put_chars.c ft_strnew.c ft_strdel.c\
ft_strclr.c ft_striter.c ft_unsigned_len.c ft_put_unsigned_base.c ft_striteri.c\
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c\
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstdel.c\
ft_intlen.c ft_strrev.c ft_strjoin_free.c ft_strsub_free.c ft_sqrt.c\
ft_strnew_chr.c ft_strccpy.c ft_itoa_base.c ft_ll_len.c ft_putnbr_ll.c\
ft_swap.c ft_hexa_to_int.c ft_is_hexa.c ft_hexa_len.c
GNL = get_next_line.c
FT_PRINTF = ft_printf.c list_convs.c print.c is_funcs.c create_conv.c add_flags.c\
print_cs.c print_di.c print_p.c print_unsigned.c print_f.c double_to_str.c\
style.c asterisk.c add_length_mod.c print_utilities.c
LIBFTDIR = $(patsubst %, libft/%, $(LIBFT))
GNLDIR = $(patsubst %, gnl/%, $(GNL))
FT_PRINTFDIR = $(patsubst %, ft_printf/%, $(FT_PRINTF))
SRCS = $(LIBFTDIR) $(GNLDIR) $(FT_PRINTFDIR)
SRCFILES = $(LIBFT) $(GNL) $(FT_PRINTF)
OBJS = $(patsubst %.c, %.o, $(SRCFILES))

all: $(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
