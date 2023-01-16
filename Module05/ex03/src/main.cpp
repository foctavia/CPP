/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:05 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/18 10:05:03 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	InternTest( void )
{
	std::cout << YELLOW("*******************INTERN TEST********************") << std::endl;
		
	std::cout <<std::endl << BLUE("***Constructing***") << std::endl << std::endl;
	
	Bureaucrat	*beur1 = new Bureaucrat(PURPLE("Vice President"), 2);
	Bureaucrat	*beur2 = new Bureaucrat(PURPLE("Chief of Secretary"), 23);
	Bureaucrat	*beur3 = new Bureaucrat(PURPLE("Senior Advisor"), 70);
	Bureaucrat	*beur4 = new Bureaucrat(PURPLE("Junior Secretary"), 139);
	AForm		*form;
	Intern		busyIntern;
	
	std::cout << std::endl << BLUE("***Testing***") << std::endl << std::endl;

	std::cout << beur1 << std::endl
		<< beur2 << std::endl
		<< beur3 << std::endl
		<< beur4 << std::endl;
	
	form = busyIntern.makeForm("Shrubbery Creation", "Central Park");
	if (form)
	{
		std::cout << std::endl << form << std::endl;
		beur4->signForm(*form);
		beur3->executeForm(*form);
		delete form;
	}
	std::cout << std::endl;
	form = busyIntern.makeForm("Robotomy Request", "Bender");
	if (form)
	{
		std::cout << std::endl << form << std::endl;
		beur3->signForm(*form);
		beur2->executeForm(*form);
		delete form;
	}
	std::cout << std::endl;
	form = busyIntern.makeForm("Presidential Pardon", "petty thief");
	if (form)
	{
		std::cout << std::endl << form << std::endl;
		beur2->signForm(*form);
		beur1->executeForm(*form);
		delete form;
	}
	std::cout << std::endl;
	form = busyIntern.makeForm(RED("Death Penalty Legalisation"), "sex offender");
	if (form)
	{
		std::cout << std::endl << form << std::endl;
		beur2->signForm(*form);
		beur1->executeForm(*form);
		delete form;
	}

	std::cout << std::endl
		<< BLUE("***Deconstructing***") << std::endl << std::endl;
	delete beur1;
	delete beur2;
	delete beur3;
	delete beur4;
	std::cout << std::endl;
}

int	main( void )
{
	InternTest();
	return 0;
}
