/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:05 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/16 17:23:04 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	formsCreationTest( void )
{
	std::cout << YELLOW("***************FORMS CREATION TEST****************") << std::endl;
		
	std::cout <<std::endl
		<< BLUE("***Constructing***") << std::endl << std::endl;
	AForm	*test1 = NULL;
	AForm	*test2 = NULL;
	AForm	*test3 = NULL;
	AForm	*test4 = NULL;
	
	try
	{
		test1 = new AForm("FO.1.9", 0, 120);
	}
	catch(std::exception &e)
	{
		std::cerr << RED("ERROR : Construction failed : ") << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test2 = new ShrubberyCreationForm(PURPLE("garden"));
	}
	catch(std::exception &e)
	{
		std::cerr << RED("ERROR : Construction failed : ") << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test3 = new RobotomyRequestForm(PURPLE("sex offender"));
	}
	catch(std::exception &e)
	{
		std::cerr << RED("ERROR : Construction failed : ") << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test4 = new PresidentialPardonForm(PURPLE("petty thief"));
	}
	catch(std::exception &e)
	{
		std::cerr << RED("ERROR : Construction failed : ") << e.what() << std::endl;
	}
	
	std::cout << std::endl << BLUE("***Deconstructing***") << std::endl << std::endl;
	
	if (test1)
		delete test1;
	if (test2)
		delete test2;
	if (test3)
		delete test3;
	if (test4)
		delete test4;

	std::cout << std::endl;
}

void	shrubberyCreationFormTest( void )
{
	std::cout << YELLOW("***********SHRUBBERY CREATION FORM TEST***********") << std::endl;
		
	std::cout <<std::endl << BLUE("***Constructing***") << std::endl << std::endl;
	
	Bureaucrat	*beur1 = new Bureaucrat(PURPLE("Senior Advisor"), 15);
	Bureaucrat	*beur2 = new Bureaucrat(PURPLE("Junior Secretary"), 140);
	AForm		*form = new ShrubberyCreationForm("Central Park");
	
	std::cout << std::endl << BLUE("***Testing***") << std::endl << std::endl;

	std::cout << beur1 << std::endl
		<< beur2 << std::endl
		<< form << std::endl;
		
	try
	{
		form->execute(*beur2);
	}
	catch (std::exception &e)
	{
		std::cerr << beur2->getName() << RED(" couldn't execute form ") << form->getName()
			<< " because " << e.what() << std::endl;
	}
	beur2->signForm(*form);
	try
	{
		form->beSigned(*beur1);
	}
	catch (std::exception &e)
	{
		std::cerr << beur1->getName() << RED(" couldn't sign form ") << form->getName()
			<< " because " << e.what() << std::endl;
	}
	beur1->executeForm(*form);

	std::cout << std::endl
		<< BLUE("***Deconstructing***") << std::endl << std::endl;
	delete beur1;
	delete beur2;
	delete form;
	std::cout << std::endl;
}

void	robotomyRequestFormTest( void )
{
	std::cout << YELLOW("************ROBOTOMY REQUEST FORM TEST************") << std::endl;
		
	std::cout <<std::endl << BLUE("***Constructing***") << std::endl << std::endl;
	
	Bureaucrat			*beur1 = new Bureaucrat(PURPLE("General"), 10);
	Bureaucrat			*beur2 = new Bureaucrat(PURPLE("Junior State Advisor"), 70);
	RobotomyRequestForm	*form = new RobotomyRequestForm(PURPLE("sex offender"));
	
	std::cout << std::endl << BLUE("***Testing***") << std::endl << std::endl;

	std::cout << beur1 << std::endl
		<< beur2 << std::endl
		<< form << std::endl;
		
	try
	{
		form->execute(*beur2);
	}
	catch (std::exception &e)
	{
		std::cerr << beur2->getName() << RED(" couldn't execute form ") << form->getName()
			<< " because " << e.what() << std::endl;
	}
	beur2->signForm(*form);
	try
	{
		form->beSigned(*beur1);
	}
	catch (std::exception &e)
	{
		std::cerr << beur1->getName() << RED(" couldn't sign form ") << form->getName()
			<< " because " << e.what() << std::endl;
	}
	beur1->executeForm(*form);
	beur1->executeForm(*form);


	std::cout << std::endl
		<< BLUE("***Deconstructing***") << std::endl << std::endl;
	delete beur1;
	delete beur2;
	delete form;
	std::cout << std::endl;
}

void	presidentialPardonFormTest( void )
{
	std::cout << YELLOW("**********PRESIDENTIAL PARDON FORM TEST***********") << std::endl;
		
	std::cout <<std::endl << BLUE("***Constructing***") << std::endl << std::endl;
	
	Bureaucrat				*beur1 = new Bureaucrat(PURPLE("Vice President"), 2);
	Bureaucrat				*beur2 = new Bureaucrat(PURPLE("Chief of Secretary"), 23);
	PresidentialPardonForm	*form = new PresidentialPardonForm(PURPLE("petty thief"));
	
	std::cout << std::endl << BLUE("***Testing***") << std::endl << std::endl;

	std::cout << beur1 << std::endl
		<< beur2 << std::endl
		<< form << std::endl;
		
	try
	{
		form->execute(*beur2);
	}
	catch (std::exception &e)
	{
		std::cerr << beur2->getName() << RED(" couldn't execute form ") << form->getName()
			<< " because " << e.what() << std::endl;
	}
	beur2->signForm(*form);
	try
	{
		form->beSigned(*beur1);
	}
	catch (std::exception &e)
	{
		std::cerr << beur1->getName() << RED(" couldn't sign form ") << form->getName()
			<< " because " << e.what() << std::endl;
	}
	beur1->executeForm(*form);

	std::cout << std::endl
		<< BLUE("***Deconstructing***") << std::endl << std::endl;
	delete beur1;
	delete beur2;
	delete form;
	std::cout << std::endl;
}

int	main( void )
{
	formsCreationTest();
	std::cout << std::endl;
	shrubberyCreationFormTest();
	std::cout << std::endl;
	robotomyRequestFormTest();
	std::cout << std::endl;
	presidentialPardonFormTest();

	return 0;
}
