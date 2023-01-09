/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:20 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 00:08:11 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" )
{
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog( Dog const &src ) : Animal( "Dog" )
{
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;	
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=( Dog const &rhs )
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->getType() << " : WOUF WOUF WOUF" << std::endl;
}
