/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:25 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 00:20:31 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "Unknown" )
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal( const std::string type ) : _type( type )
{
	std::cout << "Animal type " << this->_type << " constructor called" << std::endl;
	return ;
}

Animal::Animal( Animal const &src )
{
	*this = src;
	std::cout << "Animal type " << this->_type << " copy constructor called" << std::endl;
	return ;
}

Animal::~Animal( void )
{
	std::cout << "Animal type " << this->_type << " destructor called" << std::endl;
	return ;
}

Animal	&Animal::operator=( Animal const &rhs )
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Animal type " << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal makes noisy sound!" << std::endl;
}
