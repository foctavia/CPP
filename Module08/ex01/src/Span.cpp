/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:06:58 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/23 01:33:29 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) :  _vct( 0 ), _max( 0 )
{
	return ;
}

Span::Span( unsigned int N ) : _max( N )
{
	this->_vct.reserve( N );
	return ;
}

Span::Span( Span const &src )
{
	*this = src;
	return ;
}

Span::~Span( void )
{
	return ;
}

Span	&Span::operator=( Span const &rhs )
{
	if (this != &rhs)
	{
		this->_vct = rhs._vct;
		this->_max = rhs._max;
	}
	return (*this);
}

unsigned int	Span::getMax( void ) const
{
	return (this->_max);
}

std::vector<int> const	&Span::getVct( void ) const
{
	return (this->_vct);
}

void	Span::addNumber( int nb )
{
	if (this->_vct.size() == this->_max)
		throw Span::reachedMaxCapacityException();
	else
		this->_vct.push_back(nb);
}

void	Span::addNumber( std::vector<int>::const_iterator first, std::vector<int>::const_iterator last )
{
	unsigned int						dist = std::distance(first, last);
	std::vector<int>::const_iterator	post = this->_vct.end() - 1;
	
	if (this->_vct.size() + dist > this->_max)
		throw Span::reachedMaxCapacityException();
	else
		this->_vct.insert(post, first, last);
}

unsigned int	Span::shortestSpan(void ) const
{
	if (this->_vct.size() < 2)
		throw Span::noSpanFound();

	std::vector<int>	tmp(this->_vct);
	
	std::sort(tmp.begin(), tmp.end());
	
	std::vector<int>::iterator	current = tmp.begin();
	std::vector<int>::iterator	next = current + 1;
	
	unsigned int				res = (unsigned int)(*next++ - *current++);
	while (next != tmp.end())
	{
		if ((unsigned int)(*next - *current) < res)
			res = (unsigned int)(*next - *current);
		current++;
		next++;
	}
	return (res);
}

unsigned int	Span::longestSpan( void ) const
{
	if (this->_vct.size() < 2)
		throw Span::noSpanFound();

	std::vector<int>	tmp(this->_vct);
	
	std::sort(tmp.begin(), tmp.end());
	
	return (tmp.back() - tmp.front());
}

const char	*Span::reachedMaxCapacityException::what( void ) const throw()
{
	return (RED("ERROR : Container is already reached the maximum capacity"));
}

const char	*Span::noSpanFound::what( void ) const throw()
{
	return (RED("RESULT : No span can be found"));
}

std::ostream	&operator<<( std::ostream &obj, Span const &insert )
{
	std::vector<int>::const_iterator	it = insert.getVct().begin();

	obj << "{ ";
	for (; it != insert.getVct().end() ; it++)
	{
		obj << *it;
		if (it + 1 != insert.getVct().end())
			obj << ", ";
	}
	obj << " }" << std::endl;

	return (obj);
}
