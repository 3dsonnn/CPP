# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 08:02:58 by efinda            #+#    #+#              #
#    Updated: 2024/12/10 18:20:21 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	brain

SRC = main.cpp

COMP = c++
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJ = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Creating Executable..."

%.o:	%.cpp
	@$(COMP) $(FLAGS) -c $< -o $@
	@echo "Creating Object..."

clean:	
	@$(RM) $(OBJ)
	@echo "Cleaning Object..."
	
fclean:	clean
	@$(RM) $(NAME)
	@echo "Cleaning Executable..."

re:	fclean all

.PHONY: all clean fclean re
