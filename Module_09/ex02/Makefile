# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 17:54:38 by efinda            #+#    #+#              #
#    Updated: 2025/06/24 12:46:43 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = PmergeMe.hpp

OBJ =	main.o		\
		PmergeMe.o	\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -o $@

main.o: main.cpp $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

PmergeMe.o: PmergeMe.cpp $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re