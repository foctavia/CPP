/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:59:56 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/18 10:03:55 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern( Intern const &src )
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return ;
}

Intern::~Intern( void )
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern	&Intern::operator=( Intern const &rhs )
{
	(void)rhs;
	std::cout << "Intern assignment operator called" << std::endl;
	return (*this);
}

static AForm	*makeShrubberyCreation( const std::string target )
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyRequest( const std::string target )
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialPardon( const std::string target )
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm( const std::string name, const std::string target )
{
	AForm		*((*forms_func[3])( const std::string target )) = { &makeShrubberyCreation, &makeRobotomyRequest, &makePresidentialPardon };
	std::string	forms[3] = { "Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern " << GREEN("creates ") << name << " form" << std::endl;
			return ((*forms_func[i])(target));
		}
	}
	
	std::cerr << RED("ERROR : Form Creation for ") << name << RED(" has failed") << std::endl
		<< "Intern can only create form for " 
		<< GREEN("Shrubbery Creation / Robotomy Request / Presidential Pardon") << std::endl;
	return (NULL);
}
