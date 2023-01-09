/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:22 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 00:06:04 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" )
{
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat( Cat const &src ) : Animal( "Cat" )
{
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
	return ;	
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=( Cat const &rhs )
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->getType() << " : MEAOW MEAOW MEAOW" << std::endl;
}
