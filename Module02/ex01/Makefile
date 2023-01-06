# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:42:31 by foctavia          #+#    #+#              #
#    Updated: 2023/01/06 17:43:15 by foctavia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		= fixedPointNumber

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g

INCDIR		= inc/
SRCDIR		= src/
OBJDIR		= obj/

SRC			= main.cpp \
				Fixed.cpp
				
OBJ			= $(addprefix ${OBJDIR}, ${SRC:%.cpp=%.o})
INC			= -I./$(INCDIR)

# Rules
all			: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
			@mkdir -p ${@D}
			$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME)		: $(OBJ)
			$(CXX) $(CXXFLAGS) $(INC) $(OBJ) -o $@
			@echo "Compiling fixedPointNumber"$(GREEN)"\tOK"$(RESET)

clean		:
			rm -rf $(OBJDIR)

fclean		: clean
			rm -f $(NAME)

re			: fclean
			make all

.PHONY		: all clean fclean re
