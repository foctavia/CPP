/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:42:00 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 19:19:51 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain( Brain const &src )
{
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
	return ;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain	&Brain::operator=( Brain const &rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
}

const std::string	Brain::getIdeas( size_t i ) const
{
	if (i < 100)
		return (this->_ideas[i]);
	else
	{
		std::cout << "Maximum capacity is 100 ideas / brain" << std::endl;
		return 0;
	}
}

void	Brain::setIdeas( size_t i, std::string idea )
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Reached maximum capacity of 100 ideas / brain" << std::endl;
}

