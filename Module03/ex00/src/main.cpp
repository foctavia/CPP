/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:08:08 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 02:03:07 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	random;
	ClapTrap	john("John");
	
	john.attack(random.getName());
	john.takeDamage(5);
	john.beRepaired(15);
	
	for (int i = 0; i < 10; i++)
		john.attack(random.getName());
		
	john.takeDamage(20);
	john.beRepaired(5);
	return 0;
}
