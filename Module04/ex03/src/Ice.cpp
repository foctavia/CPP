/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:58 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 01:44:49 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" )
{
	return ;
}

Ice::Ice( Ice const &src ) : AMateria( src )
{
	return ;
}

Ice::~Ice( void )
{
	return ;
}

Ice	&Ice::operator=( Ice const &rhs )
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

AMateria	*Ice::clone( void ) const
{
	AMateria	*ice = new Ice(*this);
	if (!ice)
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}
	return (ice);
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
