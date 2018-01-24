# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgore <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 17:00:24 by pgore             #+#    #+#              #
#    Updated: 2017/01/05 18:15:17 by pgore            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLG = -Wall -Wextra -Werror
INC = -I ./includes/
SRC = format_i_d.c\
		format_s.c\
		ft_format_hex.c\
		ft_lib1.c\
		ft_lib2.c\
		ft_lib3.c\
		ft_lib4.c\
		ft_parse_arg.c\
		parse_flags.c\
		precision.c\
		fmt_s.c\
		ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLG) -o $@ -c $^ $(INC)

test: 
	$(CC) $(SRC) printf_main.c $(INC) -o rekt

clean:
	rm -f $(OBJ) ft_printf.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
