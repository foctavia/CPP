/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:20 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 20:49:00 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" )
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}
	return ;
}

Dog::Dog( Dog const &src ) : Animal( "Dog" )
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}
	*this->_brain = *src._brain;
	return ;	
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=( Dog const &rhs )
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdeas(i, rhs._brain->getIdeas(i));
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->getType() << " : WOUF WOUF WOUF" << std::endl;
}

const std::string Dog::getIdeas( size_t i ) const
{
	return (this->_brain->getIdeas(i));
}

void	Dog::setIdeas( size_t i, std::string idea )
{
	this->_brain->setIdeas(i, idea);
}
