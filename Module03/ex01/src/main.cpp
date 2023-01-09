/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:09:13 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 10:36:17 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	random;
	ScavTrap	john("John");
	
	john.attack(random.getName());
	john.takeDamage(5);
	john.beRepaired(15);
	
	for (int i = 0; i < 10; i++)
		john.attack(random.getName());
		
	john.takeDamage(20);
	john.beRepaired(5);
	john.guardGate();
	john.takeDamage(95);
	john.beRepaired(15);
	john.guardGate();

	return 0;	
}
