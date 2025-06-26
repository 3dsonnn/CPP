# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 06:38:18 by efinda            #+#    #+#              #
#    Updated: 2025/06/26 16:51:19 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = BitcoinExchange.hpp

OBJS =	main.o				\
		BitcoinExchange.o	\

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