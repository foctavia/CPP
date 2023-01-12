/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:05 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/12 02:54:34 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	secondTest( void )
{
	std::cout << "*******************SECOND TEST********************"
		<< std::endl;
		
	std::cout <<std::endl
		<< "***Constructing***" << std::endl << std::endl;
	Bureaucrat	*beur1 = new Bureaucrat("Senior Manager", 5);
	Bureaucrat	*beur2 = new Bureaucrat("Junior Salesman", 140);
	Form		*form1 = new Form("AF.1.5", 10, 15);
	Form		*form2 = new Form();
	
	std::cout << std::endl
		<< "***Testing***"<< std::endl << std::endl;	
	try
	{
		form1->beSigned(*beur2);
	}
	catch (std::exception &e)
	{
		std::cerr << beur2->getName() << " couldn't sign form " << form1->getName()
			<< " because " << e.what() << std::endl;
	}
	beur1->signForm(*form1);
	try
	{
		form2->beSigned(*beur2);
	}
	catch (std::exception &e)
	{
		std::cerr << beur2->getName() << " couldn't sign form " << form2->getName()
			<< " because " << e.what() << std::endl;
	}
	beur1->signForm(*form2);

	std::cout << std::endl
		<< "***Deconstructing***" << std::endl << std::endl;
	delete beur1;
	delete beur2;
	delete form1;
	delete form2;
	std::cout << std::endl;
}

void	firstTest( void )
{
	std::cout << "********************FIRST TEST********************" 
		<< std::endl;
		
	std::cout <<std::endl
		<< "***Constructing***" << std::endl << std::endl;
	Form	*test1 = NULL;
	
	try
	{
		test1 = new Form("FO.1.9", 0, 120);
	}
	catch(std::exception &e)
	{
		std::cerr << "ERROR : Construction failed : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test1 = new Form("FO.1.0", 12, 0);
	}
	catch(std::exception &e)
	{
		std::cerr << "ERROR : Construction failed : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test1 = new Form("FO.3.3", 122, 155);
	}
	catch(std::exception &e)
	{
		std::cerr << "ERROR : Construction failed : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test1 = new Form("FO.1.7", 3723223950, 1);
	}
	catch(std::exception &e)
	{
		std::cerr << "ERROR : Construction failed : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test1 = new Form("TOP SECRET", 1, 1);
	}
	catch(std::exception &e)
	{
		std::cerr << "ERROR : Construction failed : " << e.what() << std::endl;
	}
	
	if (test1)
	{
		std::cout << std::endl
			<< "***Deconstructing***" << std::endl << std::endl;
		delete test1;
	}

	std::cout << std::endl;
}

int	main( void )
{
	firstTest();
	std::cout << std::endl;
	secondTest();
	std::cout << std::endl;

	return 0;
}
