/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:01 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/13 19:10:23 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void	firstTest( void )
{
	std::cout << "***************DEFAULT CONSTRUCTOR****************"
		<< std::endl << std::endl;
	
	const Animal	*animals[5];
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Animal #" << i + 1 << std::endl;
		if (i < 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		if (!animals[i])
		{
			std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
			exit(1);
		}
		std::cout << std::endl;

	}
	std::cout << std::endl
		<< "**********************TESTER**********************"
		<< std::endl << std::endl;
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Animal #" << i + 1 << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl
		<< "********************DESTRUCTOR********************"
		<< std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Animal #" << i + 1 << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
}

void	secondTest( void )
{
	std::cout << "***************DEFAULT CONSTRUCTOR****************"
		<< std::endl << std::endl;
	
	Dog	*dogs[3];
	
	for (int i = 0; i < 2; i++)
	{	
		std::cout << "Dogs #" << i + 1 << std::endl;
		dogs[i] = new Dog();
		if (!dogs[i])
		{
			std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
			exit(1);
		}
		std::cout << std::endl;
	}
	
	dogs[0]->setIdeas(0, "I WOOF MY HOOMAN!!");
	dogs[0]->setIdeas(1, "LET'S RUN!!");
	dogs[0]->setIdeas(2, "JACKPOT!! IT'S A STICK");
	dogs[0]->setIdeas(3, "GRRWWLLL!!");

	std::cout << std::endl
		<< "***************ASSIGNMENT OPERATOR****************"
		<< std::endl << std::endl;
	
	*dogs[1] = *dogs[0];
	std::cout << std::endl;
	
	std::cout << std::endl
		<< "*****************COPY CONSTRUCTOR*****************"
		<< std::endl << std::endl;
	
	std::cout << "Dogs #3" << std::endl;
	dogs[2] = new Dog(*dogs[0]);
	if (!dogs[2])
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}

	std::cout << std::endl << std::endl
		<< "*********************DISPLAY**********************"
		<< std::endl << std::endl;
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Dogs #" << i + 1 << std::endl;
		for(int j = 0; j < 4; j++)
			std::cout << "Thinking : " << dogs[i]->getIdeas(j) << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl
		<< "********************DESTRUCTOR********************"
		<< std::endl << std::endl;

	std::cout << "Dogs #1" << std::endl;
	delete dogs[0];	
		
	std::cout << std::endl << std::endl
		<< "**********************TESTER**********************"
		<< std::endl << std::endl;
	
	for (int i = 1; i < 3; i++)
	{
		std::cout << "Dogs #" << i + 1 << std::endl;
		for(int j = 0; j < 4; j++)
			std::cout << "Thinking : " << dogs[i]->getIdeas(j) << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << std::endl
		<< "********************DESTRUCTOR********************"
		<< std::endl << std::endl;

	for (int i = 1; i < 3; i++)
	{
		std::cout << "Dogs #" << i + 1 << std::endl;
		delete dogs[i];
		std::cout << std::endl;
	}

	// std::cout << std::endl << std::endl;

	// Dog basic;
	// std::cout << std::endl;
	// {
	// 	Dog tmp = basic;
	// }
	// std::cout << std::endl;
}

int main()
{
	firstTest();
	std::cout << std::endl;
	secondTest();
	return 0;
}