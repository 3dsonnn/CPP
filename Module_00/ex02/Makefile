# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 16:57:36 by efinda            #+#    #+#              #
#    Updated: 2025/04/12 16:58:42 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	dreams

SRC =	tests.cpp	\
		Account.cpp	\
	
COMP =	c++
FLAGS =	-Wall -Wextra -Werror
RM =	rm -rf

OBJ =	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
