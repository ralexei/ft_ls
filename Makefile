# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgore <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 18:33:50 by pgore             #+#    #+#              #
#    Updated: 2017/04/03 14:17:20 by pgore            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc -Wall -Wextra -Werror
INC = -I ./includes/
LBFT = libft
PRNTF = ft_printf
SRC = src/arr_util.c \
	  src/file.c \
	  src/error_handle.c \
	  src/ls_ing.c \
	  src/main.c \
	  src/put_fold.c \
	  src/sort.c \
	  src/tools.c \
	  src/utils.c

all: $(NAME)	

$(NAME):
	make -C libft
	make -C ft_printf
	$(CC) $(SRC) $(INC) -L$(LBFT) -lft -L$(PRNTF) -lftprintf -o $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
