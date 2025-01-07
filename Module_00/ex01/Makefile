# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 17:34:11 by efinda            #+#    #+#              #
#    Updated: 2024/12/07 16:14:03 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	phonebook

SRC =	Contact.cpp	\
	phonebook.cpp	\
	PhoneBook.cpp	\
	utils.cpp
	
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
