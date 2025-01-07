# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:50:12 by efinda            #+#    #+#              #
#    Updated: 2024/12/03 17:23:05 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Megaphone

SRC =	megaphone.cpp
OBJ =	$(SRC:.cpp=.o)

COMP =	c++
FLAGS =	-Wall -Wextra -Werror -std=c++98
RM = rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Creating executable..."

%.o: %.cpp
	@$(COMP) $(FLAGS) -c $< -o $@
	@echo "Creating object..."

clean:
	@$(RM) $(OBJ)
	@echo "Cleaning object..."

fclean:	clean
	@$(RM) $(NAME)
	@echo "Cleaning executable..."

re:	fclean	all

.PHONY: all clean fclean re
