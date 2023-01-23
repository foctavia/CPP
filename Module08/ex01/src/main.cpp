/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:07:10 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/23 13:54:24 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// test the shortestSpan / longest span function with empty vector
void	emptyTest( void )
{
	std::cout << BLUE("***Empty Test***") << std::endl << std::endl;
	
	Span sp = Span(1);

	std::cout << "sp " << sp << std::endl;
	
	try
	{
		std::cout << "sp shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "sp longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

// test addNumber with single parameter
void	smallTest( void )
{
	std::cout << BLUE("***Small Test***") << std::endl << std::endl;
	
	Span sp = Span(5);

	try
	{
		std::cout << "Adding numbers to sp ..." << std::endl << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(19);	
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << "sp " << sp << std::endl;
	
	try
	{
		std::cout << "sp shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "sp longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

// generates random number from 1 to 100 (range is modifiable)
unsigned int	generator( void )
{
	unsigned int	nb = 1 + (rand() % 100);
	
	return (nb);
}

// test addNumber with a range of iterator
void	biggerTest( void )
{
	std::cout << BLUE("***Bigger Test***") << std::endl << std::endl;
	
	Span				sp = Span(10);
	std::vector<int>	add(10);
	
	std::srand((unsigned)time(NULL));
	std::generate(add.begin(), add.end(), generator);

	try
	{
		std::cout << "Adding vector of 10 numbers to sp ..." << std::endl << std::endl;
		sp.addNumber(add.begin(), add.end());
		sp.addNumber(add.begin(), add.end());	
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << "sp " << sp << std::endl;
	
	try
	{
		std::cout << "sp shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "sp longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

// generates random number from 1 to 10001 (range is modifiable)
unsigned int	big_generator( void )
{
	unsigned int	nb = 1 + (rand() % 15000);
	
	return (nb);
}

// test addNumber with a range of iterator for 10000 numbers
void	biggestTest( void )
{
	std::cout << BLUE("***Biggest Test***") << std::endl << std::endl;
	
	Span				sp = Span(15000);
	std::vector<int>	add(15000);
	
	std::srand((unsigned)time(NULL));
	std::generate(add.begin(), add.end(), big_generator);

	try
	{
		std::cout << "Adding vector of 15000 numbers to sp ..." << std::endl << std::endl;
		sp.addNumber(add.begin(), add.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	try
	{
		std::cout << "sp shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "sp longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

int main( void )
{
	emptyTest();
	std::cout << std::endl;
	smallTest();
	std::cout << std::endl;
	biggerTest();
	std::cout << std::endl;
	biggestTest();
	return 0;
}
