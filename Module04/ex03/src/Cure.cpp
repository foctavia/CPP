/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:53 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 01:45:38 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" )
{
	return ;
}

Cure::Cure( Cure const &src ) : AMateria( src )
{
	return ;
}

Cure::~Cure( void )
{
	return ;
}

Cure	&Cure::operator=( Cure const &rhs )
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

AMateria	*Cure::clone( void ) const
{
	AMateria	*cure = new Cure(*this);
	if (!cure)
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}
	return (cure);
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
