# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 17:54:38 by efinda            #+#    #+#              #
#    Updated: 2025/06/26 12:16:38 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = PmergeMe.hpp

OBJS =	main.o		\
		PmergeMe.o	\

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re