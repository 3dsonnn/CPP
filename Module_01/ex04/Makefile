# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 16:10:54 by efinda            #+#    #+#              #
#    Updated: 2024/12/12 16:10:57 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	search_and_replace

SRC =	main.cpp	\
	checks.cpp	\
	open.cpp	\
	replace.cpp

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
