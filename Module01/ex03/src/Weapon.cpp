/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:48:07 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 15:39:23 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

const std::string	&Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( const std::string &type )
{
	this->_type = type;
}
