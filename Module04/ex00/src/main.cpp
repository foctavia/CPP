/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:01 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/13 15:28:32 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
	std::cout << "********************ANIMAL CLASS********************" << std::endl << std::endl;
	{	
		std::cout << "*** Constructing ***" << std::endl << std:: endl;
		
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl << "*** Testing ***" << std::endl << std::endl;
		
		std::cout << "Animal type : " << j->getType() << " " << std::endl;
		std::cout << "Animal type : " << i->getType() << " " << std::endl;
		
		std::cout << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl << "*** Destructing ***" << std::endl << std::endl;

		delete meta;
		delete j;
		delete i;

		std::cout << std::endl;
	}
	std::cout << "******************WRONGANIMAL CLASS******************" << std::endl << std::endl;
	{	
		std::cout << "*** Constructing ***" << std::endl << std:: endl;
		
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* k = new WrongCat();
		const WrongCat* l = new WrongCat();

		std::cout << std::endl << "*** Testing ***" << std::endl << std::endl;


		std::cout << "Animal type : " << k->getType() << " " << std::endl;
		std::cout << "Animal type : " << l->getType() << " " << std::endl;

		
		std::cout << std::endl;

		k->makeSound();
		l->makeSound();
		meta->makeSound();
		
		std::cout << std::endl << "*** Destructing ***" << std::endl << std::endl;

		delete meta;
		delete k;
		delete l;

		std::cout << std::endl;
	}
	return 0;
}
