/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:00:32 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 00:20:16 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "WrongUnknown" )
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const std::string type ) : _type( type )
{
	std::cout << "WrongAnimal type " << this->_type << " constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src )
{
	*this = src;
	std::cout << "WrongAnimal type " << this->_type << " copy constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal type " << this->_type << " destructor called" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs )
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "WrongAnimal type " << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal does not make sound!" << std::endl;
}
