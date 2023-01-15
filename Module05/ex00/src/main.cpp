/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:05 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/15 19:07:03 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// firstTest with object allocated dynamicly with default constructor.
// failed at decrementing grade and object destroyed with delete.
void	firstTest( void )
{
	std::cout << "********************FIRST TEST********************"
		<< std::endl;
		
	std::cout <<std::endl
		<< "***Constructing***" << std::endl << std::endl;
	Bureaucrat	*test1 = new Bureaucrat();
	
	std::cout << std::endl
		<< "***Testing***"<< std::endl << std::endl;	
	try
	{
		test1->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR : Grade increment failed : " << e.what() << std::endl;
	}
	try
	{	
		test1->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERROR : Grade decrement failed :" << e.what() << std::endl;	
	}
	try
	{
		test1->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERROR : Grade decrement failed : " << e.what() << std::endl;
	}

	std::cout << std::endl
		<< "***Deconstructing***" << std::endl << std::endl;
	delete test1;
	std::cout << std::endl;
}

// second test with object created at heap with constructor with name and grade.
// failed at incrementing grade and object destroyed by default when exiting the function.
void	secondTest( void )
{
	std::cout << "*******************SECOND TEST********************"
		<< std::endl;
		
	std::cout <<std::endl
		<< "***Constructing***" << std::endl << std::endl;
	Bureaucrat	test2 = Bureaucrat("John", 1);
	
	std::cout << std::endl
		<< "***Testing***"<< std::endl << std::endl;	
	try
	{
		test2.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERROR : Grade decrement failed : " << e.what() << std::endl;
	}
	try
	{	
		test2.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR : Grade increment failed : " << e.what() << std::endl;	
	}
	try
	{
		test2.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR : Grade increment failed : " << e.what() << std::endl;
	}

	std::cout << std::endl
		<< "***Deconstructing***" << std::endl << std::endl;
}

// third test with object allocated dynamicaly with grade that is too low inside try bracket.
// failed at construction of the object.
// potential memory leak hence the additional protection of "if test3 exist"
void	thirdTest( void )
{
	std::cout << "********************THIRD TEST********************"
		<< std::endl;
		
	std::cout <<std::endl
		<< "***Constructing***" << std::endl << std::endl;
	Bureaucrat	*test3 = NULL;
	
	try
	{
		test3 = new Bureaucrat(0);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR : Construction failed : " << e.what() << std::endl;
	}
	
	if (test3)
	{
		std::cout << std::endl
			<< "***Deconstructing***" << std::endl << std::endl;
		delete test3;
	}

	std::cout << std::endl;
}

// fourth test with creation of object in heap inside try bracket.
// creation succeed but failed at decrementing.
// stack unwinding proccess caused the destructor called before the error message appear.
// resource : https://learn.microsoft.com/en-us/cpp/cpp/exceptions-and-stack-unwinding-in-cpp?redirectedfrom=MSDN&view=msvc-170
void	fourthTest( void )
{
	std::cout << "*******************FOURTH TEST********************"
		<< std::endl;
		
	std::cout <<std::endl
		<< "***Constructing***" << std::endl << std::endl;
	
	try
	{
		Bureaucrat	test4 = Bureaucrat("Ben");
		std::cout << std::endl
			<< "***Testing***"<< std::endl << std::endl;
		test4.incrementGrade();	
		test4.decrementGrade();
		test4.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "ERROR : Grade increment / decrement failed : " << e.what() << std::endl;
	}
	
	std::cout << std::endl
		<< "***Deconstructing***" << std::endl << std::endl
		<< "INFO : This section is empty because destruction occurs the moment exception thrown."
		<< std:: endl << std::endl;
}

int	main( void )
{
	firstTest();
	std::cout << std::endl;
	secondTest();
	std::cout << std::endl << std::endl;
	thirdTest();
	std::cout << std::endl;
	fourthTest();
	std::cout << std::endl;

	return 0;
}
