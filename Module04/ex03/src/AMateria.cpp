/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:45 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 23:46:08 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) 
{
	return ;
}

AMateria::AMateria( std::string const &type ) : _type( type )
{
	return ;
}

AMateria::AMateria( AMateria const &src )
{
	*this = src;
	return ;
}

AMateria::~AMateria( void )
{
	return ;
}

AMateria	&AMateria::operator=( AMateria const &rhs )
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string const	&AMateria::getType( void ) const
{
	return (this->_type);
}

void	AMateria::use( ICharacter &target )
{
	(void)target;
}
