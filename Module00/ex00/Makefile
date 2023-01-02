# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:05:48 by foctavia          #+#    #+#              #
#    Updated: 2022/12/27 14:07:14 by foctavia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		= megaphone

CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRC			= megaphone.cpp
OBJ			= $(SRC:%.cpp=%.o)

# Rules
all			: $(NAME)

%.o			: %.cpp
			$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME)		: $(OBJ)
			$(CPP) $(CPPFLAGS) $(OBJ) -o $@
			@echo "Compiling Megaphone"$(GREEN)"\tOK"$(RESET)

clean		:
			rm -f $(OBJ)

fclean		: clean
			rm -f $(NAME)

re			: fclean
			make all

.PHONY		: all clean fclean re