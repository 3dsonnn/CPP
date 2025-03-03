# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 07:43:02 by efinda            #+#    #+#              #
#    Updated: 2025/01/30 00:12:58 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	firstOCF

SRC =	main.cpp	\
		Fixed.cpp	

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