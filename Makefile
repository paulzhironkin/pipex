# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 16:18:28 by latahbah          #+#    #+#              #
#    Updated: 2022/02/08 18:37:02 by latahbah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIST =	retrieve_path.c	pipex.c

LIB = libft/libft.a

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME)::
	@cd libft && make

$(NAME):: $(OBJ)
	gcc $(FLAGS) $(OPTFLAGS) $(OBJ) $(LIB) -I . -o $(NAME)

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean::
	@cd libft && make clean

clean::
	@rm -f $(OBJ) $(D_FILES)

fclean:: clean
	@cd libft && make fclean

fclean:: clean
	@rm -f $(NAME)

re:: fclean all
	@cd libft && make re

re:: fclean	all

.PHONY: all clean fclean re bonus
