# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 18:12:19 by foctavia          #+#    #+#              #
#    Updated: 2023/01/17 16:32:18 by foctavia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		= replace

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRC			= main.cpp

OBJ			= $(SRC:%.cpp=%.o)

# Rules
all			: $(NAME)

%.o			: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)		: $(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@
			@echo "Compiling replace"$(GREEN)"\tOK"$(RESET)

clean		:
			rm -f $(OBJ)

fclean		: clean
			rm -f $(NAME)

re			: fclean
			make all

.PHONY		: all clean fclean re
