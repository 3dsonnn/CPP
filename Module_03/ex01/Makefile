# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 23:02:11 by efinda            #+#    #+#              #
#    Updated: 2025/04/12 11:01:07 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Serena

SRC =	main.cpp		\
		ClapTrap.cpp	\
		ScavTrap.cpp

OBJ =	$(SRC:.cpp=.o)

COMP =	c++
FLAGS =	-Wall -Wextra -Werror
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