/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:07:10 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/22 22:59:08 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	displayInt( int i )
{
	std::cout << i << std::endl;
}

void	listTest( void )
{
	std::list<int>					lst;
	std::list<int>::const_iterator	it;

	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	std::cout << BLUE("***LIST TESTER***") << std::endl << std::endl
		<< "The list contains of numbers :" << std::endl;

	for_each(lst.begin(), lst.end(), displayInt);
	std::cout << std::endl;

	try
	{
		std::cout << "Try to find number 23 in the list" << std::endl;
		it = ::easyfind(lst, 23);
		if (it != lst.end())
			std::cout << GREEN("RESULT : Found occurence of the number in the list") << std::endl << std:: endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "Try to find number 19 in the list" << std::endl;
		it = ::easyfind(lst, 19);
		if (it != lst.end())
			std::cout << GREEN("RESULT : Found occurence of the number in the list") << std::endl << std:: endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

void	vectorTest( void )
{
	std::vector<int>					vct;
	std::vector<int>::const_iterator	it;

	vct.push_back(10);
	vct.push_back(23);
	vct.push_back(3);
	vct.push_back(17);
	vct.push_back(20);

	std::cout << BLUE("***VECTOR TESTER***") << std::endl << std::endl
		<< "The vector contains of numbers :" << std::endl;

	for_each(vct.begin(), vct.end(), displayInt);
	std::cout << std::endl;

	try
	{
		std::cout << "Try to find number 3 in the vector" << std::endl;
		it = ::easyfind(vct, 3);
		if (it != vct.end())
			std::cout << GREEN("RESULT : Found occurence of the number in the vector") << std::endl << std:: endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "Try to find number 90 in the vector" << std::endl;
		it = ::easyfind(vct, 90);
		if (it != vct.end())
			std::cout << GREEN("RESULT : Found occurence of the number in the vector") << std::endl << std:: endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

int	main( void )
{
	listTest();
	std::cout << std::endl;
	vectorTest();
	return (0);
}