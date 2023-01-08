/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:40 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/08 22:55:40 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	return ;
}

Point::Point( const float floatX, const float floatY ) : _x(floatX), _y(floatY)
{
	return ;
}

Point::Point( Point const &src )
{
	*this = src;
	return ;
}

Point::~Point( void )
{
	return ;
}

Point	&Point::operator=( Point const &rhs )
{
	Fixed	*x = (Fixed *)&this->_x;
	Fixed	*y = (Fixed *)&this->_y;

	*x = rhs._x;
	*y = rhs._y;
	return (*this);
}

const Fixed	Point::getX( void ) const
{
	return (this->_x);
}

const Fixed	Point::getY( void ) const
{
	return (this->_y);
}

std::ostream	&operator<<( std::ostream &obj, Point const &insert )
{
	obj << "_x: " << insert.getX() << std::endl
		<< "_y: " << insert.getY() << std::endl;
	return (obj);
}
