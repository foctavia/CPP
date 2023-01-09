/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:29 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 15:20:43 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "Zombie is born." << std::endl;
	return ;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << this->_name << " is born." << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " died for the second and the last time." << std::endl;
	return ;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
