/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:46:30 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 11:15:51 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ClapTrap	random;
	ScavTrap	john("John");
	FragTrap	mike("Mike");
	
	std::cout << std::endl;
	
	john.attack(random.getName());
	john.takeDamage(20);
	john.beRepaired(5);
	john.guardGate();
	john.takeDamage(95);
	john.beRepaired(15);
	john.guardGate();

	std::cout << std::endl;

	mike.attack(random.getName());	
	mike.takeDamage(20);
	mike.beRepaired(5);
	mike.highFivesGuys();
	mike.takeDamage(95);
	mike.beRepaired(15);
	mike.highFivesGuys();

	std::cout << std::endl;

	return 0;	
}