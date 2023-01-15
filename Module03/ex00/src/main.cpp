/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:08:08 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/15 18:12:37 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	std::cout << "***************DEFAULT CONSTRUCTOR****************"
		<< std::endl << std::endl;
		
	ClapTrap	random;
	ClapTrap	john("John");
	
	std::cout << std::endl
		<< "**********************TESTER**********************"
		<< std::endl << std::endl;
	
	john.attack(random.getName());
	john.takeDamage(5);
	john.beRepaired(15);
	
	for (int i = 0; i < 9; i++)
		john.attack(random.getName());
		
	john.takeDamage(20);
	john.beRepaired(5);

	std::cout << std::endl
		<< "********************DESTRUCTOR********************"
		<< std::endl << std::endl;
	
	return 0;
}
