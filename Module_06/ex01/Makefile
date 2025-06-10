# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 20:33:48 by efinda            #+#    #+#              #
#    Updated: 2025/06/05 20:38:54 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialization

SRC =	main.cpp				\
		Data.cpp				\
		Serializer.cpp			\

HEADERS =	Serializer.hpp		\
			Data.hpp			\

COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

OBJ =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
		@clear && echo "Created executable..."

%.o: %.cpp $(HEADERS)
	@$(COMP) $(FLAGS) $(INC) -c $< -o $@
	@clear && echo "Created objects..."

clean:
		@$(RM) $(OBJ)
		@clear && echo "Cleaned objects..."

fclean: clean
		$(RM) $(NAME)
		@clear && echo "Cleaned executable..."

re: fclean all

.PHONY: all clean fclean re