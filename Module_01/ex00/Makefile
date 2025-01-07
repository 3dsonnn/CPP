# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 07:57:14 by efinda            #+#    #+#              #
#    Updated: 2024/12/10 07:57:15 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	BraiiiiiiinnnzzzZ

SRC =	main.cpp	\
	newZombie.cpp	\
	randomChump.cpp	\
	Zombie.cpp

COMP =	c++
FLAGS =	-Wall -Wextra -Werror
RM =	rm -rf

OBJ =	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $@
	@echo "Executable Created"

%.o: %.cpp
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "Objects Cleaned"

fclean:	clean
	@$(RM) $(NAME)
	@echo "Executable Cleaned"

re:	fclean all

.PHONY: all clean fclean re
