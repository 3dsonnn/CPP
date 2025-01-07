# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 03:29:36 by efinda            #+#    #+#              #
#    Updated: 2024/12/12 03:29:37 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	harlFilter

SRC =	main.cpp	\
	Harl.cpp

COMP = c++
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJ = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Creating" $(NAME)

%.o:	%.cpp
	@$(COMP) $(FLAGS) -c $< -o $@
	@echo "Creating" $@

clean:	
	@$(RM) $(OBJ)
	@echo "Cleaning the Objects..."
	
fclean:	clean
	@$(RM) $(NAME)
	@echo "Cleaning" $(NAME)

re:	fclean all

.PHONY: all clean fclean re
