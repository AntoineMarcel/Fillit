# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 23:43:02 by amarcel           #+#    #+#              #
#    Updated: 2019/05/17 23:43:06 by amarcel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= ./src/*.c
OBJ= ./*.o

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I libft/

$(NAME): $(SRC)
		make -C ./libft/
		$(CC) -c $(CFLAGS) $(SRC) $(LIBINC)
		$(CC) -o $(NAME) $(OBJ) $(LIBFT)

all: $(NAME)

clean:
		/bin/rm -rf *.o
		/bin/rm -rf ./libft/*.o

fclean: clean
		/bin/rm -rf $(NAME)
		/bin/rm -rf ./libft/libft.a

re: fclean all

.PHONY: all, clean, fclean, re