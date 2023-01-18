# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:50:08 by foctavia          #+#    #+#              #
#    Updated: 2023/01/18 10:06:09 by foctavia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		= "\033[1;32m"
RESET		= "\033[m"

# Variables
NAME		= Intern

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g

INCDIR		= inc/
SRCDIR		= src/
OBJDIR		= obj/

SRC			= main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp
				
OBJ			= $(addprefix ${OBJDIR}, ${SRC:%.cpp=%.o})
INC			= -I./$(INCDIR)

# Rules
all			: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
			@mkdir -p ${@D}
			$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME)		: $(OBJ)
			$(CXX) $(CXXFLAGS) $(INC) $(OBJ) -o $@
			@echo "Compiling Intern"$(GREEN)"\tOK"$(RESET)

clean		:
			rm -rf $(OBJDIR)

fclean		: clean
			rm -f $(NAME)

re			: fclean
			make all

.PHONY		: all clean fclean re
