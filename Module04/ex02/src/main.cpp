/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:01 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 10:09:32 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "***************DEFAULT CONSTRUCTOR****************"
		<< std::endl << std::endl;
	
	const AAnimal	*animals[5];
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "AAnimal #" << i + 1 << std::endl;
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
		std::cout << "AAnimal #" << i + 1 << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl
		<< "********************DESTRUCTOR********************"
		<< std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "AAnimal #" << i + 1 << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
	return 0;
}