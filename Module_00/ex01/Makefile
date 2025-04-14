# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 17:34:11 by efinda            #+#    #+#              #
#    Updated: 2025/04/12 15:22:55 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	phonebook

SRC =	main.cpp		\
		PhoneBook.cpp	\
		Contact.cpp		\
		utils.cpp
	
COMP =	c++
FLAGS =	-Wall -Wextra -Werror -std=c++98
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
