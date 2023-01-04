/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:48:17 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/04 23:01:24 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	return ;	
}

HumanB::~HumanB( void )
{
	return ;
}

void	HumanB::attack( void )
{
	if (_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << "." << std::endl;
	else
		std::cout << this->_name << " is unarmed." << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}
