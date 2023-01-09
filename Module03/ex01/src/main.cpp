/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:09:13 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 11:16:02 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	random;
	ScavTrap	john("John");
	
	std::cout << std::endl;
	
	john.attack(random.getName());
	john.takeDamage(5);
	john.beRepaired(15);
	
	for (int i = 0; i < 5; i++)
		john.attack(random.getName());
		
	john.takeDamage(20);
	john.beRepaired(5);
	john.guardGate();
	john.takeDamage(95);
	john.beRepaired(15);
	john.guardGate();

	std::cout << std::endl;

	return 0;	
}
