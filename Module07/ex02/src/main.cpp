/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:38:35 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 23:00:24 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 42

void	emptyTest( void )
{
	std::cout << "***EMPTY TEST***" << std::endl << std::endl;

	Array<int>	empty;

	srand((unsigned) time(NULL));
	for (unsigned int i = 0; i < empty.size(); i++)
	{
		empty[i] = rand();
		std::cout << "empty[" << i << "] is not empty" << std::endl; 
	}
	
	std::cout << GREEN("RESULT : Default constructor with size 0 create an empty array") << std::endl << std::endl;
}

void	mirrorTest( void )
{
	std::cout << "***MIRROR TEST***" << std::endl << std::endl;
	
	// constructing a same size of Array<int> and an array of int
	Array<int>	num(MAX_VAL);
	int			*mirror = new int[MAX_VAL];

	// filling Array<int> and an array of int with the same random values
	srand((unsigned) time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int	value = rand();
		num[i] = value;
		mirror[i] = value;
	}
	
	// checking if the content of Array<int> and an array of int have the same values
	try
	{
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != num[i])
			{
				std::cerr << RED("ERROR : Mirror did not have the same value") << std::endl;
				return ;
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl; 
	}

	std::cout << GREEN("RESULT : Array<int> is equal an array of int") << std::endl << std::endl;

	delete [] mirror;
}

void	deepCopyTest( void )
{
	std::cout << "***DEEP COPY TEST***" << std::endl << std::endl;
	
	Array<int>	num(MAX_VAL);

	srand((unsigned) time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
		num[i] = rand();
		
	// constructing a copy of 'num' with assignment operator for a different size of array
	Array<int>	test1(5);
	test1 = num;
	
	// constructing a copy of 'num' with copy constructor from 'test1'
	Array<int>	test2(test1);
	
	try
	{
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (num[i] != test1[i])
			{
				std::cerr << RED("ERROR : Assignment operator did not create the same values") << std::endl;
				return ;
			}
		}
		std::cout << GREEN("RESULT : Assignment operator performs a copy of Array<int>") << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl; 
	}
	
	try
	{
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (num[i] != test2[i])
			{
				std::cerr << RED("ERROR : Copy constructor did not create the same values") << std::endl;
				return ;
			}
		}
		std::cout << GREEN("RESULT : Copy constructor performs a copy of Array<int>") << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl; 
	}

	// try to change one value of the same index between test1 and test 2, to see if it changes both array
	std::cout 
		<< "num[0]\t\t: " << num[0] << std::endl
		<< "test1[0]\t: " << test1[0] << std::endl
		<< "test2[0]\t: " << test2[0] << std::endl << std::endl;

	test1[0] = 1234567890;
	test2[0] = 0;
	
	std::cout
		<< "num[0]\t\t: " << num[0] << std::endl
		<< "test1[0]\t: " << test1[0] << std::endl
		<< "test2[0]\t: " << test2[0] << std::endl << std::endl;
	
	if (num[0] != test1[0])
		std::cout << GREEN("RESULT : Assignment operator performs a deep copy of Array<int>") << std::endl << std::endl;
	
	if (num[0] != test2[0])
		std::cout << GREEN("RESULT : Copy constructor performs a deep copy of Array<int>") << std::endl << std::endl;
}

void	indexOperatorTest( void )
{
	std::cout << "***INDEX OPERATOR TEST***" << std::endl << std::endl;
	
	Array<int>	num(MAX_VAL);

	srand((unsigned) time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
		num[i] = rand();
	
	std::cout << "Try to get the value of :" << std::endl << std::endl;

	try
	{
		std::cout << "num[-1]\t: " << num[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << "num[" << MAX_VAL << "]\t: " << num[MAX_VAL] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "num[" << MAX_VAL - 1 << "]\t: " << num[MAX_VAL - 1] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main( void )
{
	emptyTest();
	std::cout << std::endl;
	mirrorTest();
	std::cout << std::endl;
	deepCopyTest();
	std::cout << std::endl;
	indexOperatorTest();

	return (0);
}
