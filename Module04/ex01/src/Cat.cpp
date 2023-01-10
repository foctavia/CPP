/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:22 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 21:03:29 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" )
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}
	return ;
}

Cat::Cat( Cat const &src ) : Animal( "Cat" )
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "ERROR : Allocation failed : " << std::strerror(errno) << std::endl;
		exit(1);
	}
	*this->_brain = *src._brain;
	return ;	
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=( Cat const &rhs )
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdeas(i, rhs._brain->getIdeas(i));
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->getType() << " : MEAOW MEAOW MEAOW" << std::endl;
}

const std::string Cat::getIdeas( size_t i ) const
{
	return (this->_brain->getIdeas(i));
}

void	Cat::setIdeas( size_t i, std::string idea )
{
	this->_brain->setIdeas(i, idea);
}
