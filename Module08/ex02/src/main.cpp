/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:07:10 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/23 10:53:46 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	intTest( void )
{
	std::cout << BLUE("***Int Tester***") << std::endl << std::endl;
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "MutantStack top element : " << mstack.top() << std::endl;
	
	std::cout << "Removes MutantStack top element ... " << std::endl << std::endl;
	mstack.pop();
	
	std::cout << "MutantStack size : " << mstack.size() << std::endl << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "MutantStack { ";
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ", ";
		++it;
	}
	std::cout << " }" << std::endl << std::endl;

	std::cout << "MutantStack size : " << mstack.size() << std::endl << std::endl;
}

void	stringTest( void )
{
	std::cout << BLUE("***String Tester***") << std::endl << std::endl;
	
	MutantStack<std::string> mstack;
	
	mstack.push("five");
	mstack.push("seventeen");
	
	std::cout << "MutantStack top element : " << mstack.top() << std::endl;
	
	std::cout << "Removes MutantStack top element ... " << std::endl << std::endl;
	mstack.pop();
	
	std::cout << "MutantStack size : " << mstack.size() << std::endl << std::endl;
	
	mstack.push("three");
	mstack.push("five");
	mstack.push("seven hundred thirty seven");
	mstack.push("zero");
	
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	
	std::cout << "MutantStack { ";
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ", ";
		++it;
	}
	std::cout << " }" << std::endl << std::endl;

	std::cout << "MutantStack size : " << mstack.size() << std::endl << std::endl;
}

int main()
{
	intTest();
	std::cout << std::endl;
	stringTest();
	return 0;
}
