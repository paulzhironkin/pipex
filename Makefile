# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 16:18:28 by latahbah          #+#    #+#              #
#    Updated: 2022/02/19 23:26:10 by latahbah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIST =	retrieve_path.c	pipex.c utils.c \
		ft_split.c		end.c

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OPTFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	@rm -f $(OBJ) $(D_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re bonus
