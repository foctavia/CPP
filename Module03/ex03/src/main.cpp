/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:46:30 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/15 18:20:25 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	std::cout << "***************DEFAULT CONSTRUCTOR****************"
		<< std::endl << std::endl;
		
	ClapTrap	randomCT;

	std::cout << std::endl;
	
	DiamondTrap	randomDT;

	std::cout << std::endl;
	
	DiamondTrap	ben("Ben");

	std::cout << std::endl
		<< "**********************TESTER**********************"
		<< std::endl << std::endl;

	ben.whoAmI();
	ben.attack(randomCT.getName());	
	ben.takeDamage(20);
	ben.beRepaired(5);

	std::cout << std::endl;

	randomDT.whoAmI();
	randomDT.attack(randomCT.getName());	
	randomDT.takeDamage(20);
	randomDT.beRepaired(5);

	std::cout << std::endl
		<< "********************DESTRUCTOR********************"
		<< std::endl << std::endl;

	return 0;	
}