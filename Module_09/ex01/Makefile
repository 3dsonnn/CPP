# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 12:06:40 by efinda            #+#    #+#              #
#    Updated: 2025/06/23 16:56:05 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC =	main.cpp	\
		RPN.cpp		\

HEADER =	RPN.hpp	\

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

OBJ =	main.o	\
		RPN.o	\

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $@

main.o : main.cpp $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

RPN.o : RPN.cpp $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re