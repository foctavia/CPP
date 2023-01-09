/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:00:35 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 00:19:27 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" )
{
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal( "WrongCat" )
{
	*this = src;
	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;	
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs )
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << this->getType() << " : GROUWL GROUWL GROUWL" << std::endl;
}
