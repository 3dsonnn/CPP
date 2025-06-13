# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 19:50:34 by efinda            #+#    #+#              #
#    Updated: 2025/06/12 19:57:52 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abomination

SRC =	main.cpp	\

HEADER = MutantStack.hpp	\

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

OBJ = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re