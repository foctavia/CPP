# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 17:49:55 by foctavia          #+#    #+#              #
#    Updated: 2023/01/02 20:29:56 by foctavia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		= Account

CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror -g

INCDIR		= inc/
SRCDIR		= src/
OBJDIR		= obj/

SRC			= test.cpp \
				Account.cpp \
				
OBJ			= $(addprefix ${OBJDIR}, ${SRC:%.cpp=%.o})
INC			= -I./$(INCDIR)

# Rules
all			: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
			@mkdir -p ${@D}
			$(CPP) $(CPPFLAGS) $(INC) -c $< -o $@

$(NAME)		: $(OBJ)
			$(CPP) $(CPPFLAGS) $(INC) $(OBJ) -o $@
			@echo "Compiling Account"$(GREEN)"\tOK"$(RESET)

clean		:
			rm -rf $(OBJDIR)

fclean		: clean
			rm -f $(NAME)

re			: fclean
			make all

.PHONY		: all clean fclean re
