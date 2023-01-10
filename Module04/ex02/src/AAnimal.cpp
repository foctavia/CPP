/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:25 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 18:16:09 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "Unknown" )
{
	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal( const std::string type ) : _type( type )
{
	std::cout << "AAnimal type " << this->_type << " constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const &src )
{
	*this = src;
	std::cout << "AAnimal type " << this->_type << " copy constructor called" << std::endl;
	return ;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal type " << this->_type << " destructor called" << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=( AAnimal const &rhs )
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "AAnimal type " << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}

