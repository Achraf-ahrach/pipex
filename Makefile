# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 08:27:18 by aahrach           #+#    #+#              #
#    Updated: 2023/01/03 08:45:14 by aahrach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = pipex.c ft_split.c ft_strjoin.c ft_strnstr.c

BONUS_SRC = pipex_bonus.c ft_split.c ft_strjoin.c ft_strnstr.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME)


clean:
	rm -f $(OBJ) pipex_bonus.o

fclean : clean
	rm -f $(NAME)

re: fclean all
