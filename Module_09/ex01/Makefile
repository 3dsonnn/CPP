# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 12:06:40 by efinda            #+#    #+#              #
#    Updated: 2025/06/26 16:53:15 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = RPN.hpp	\

OBJS =	main.o	\
		RPN.o	\

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