/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:42:22 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/07 01:40:50 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _fixedPoint_num( 0 )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int int_num )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint_num = int_num << this->_fractional_bits;
	return ;
}

Fixed::Fixed( const float floatPoint_num )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint_num = roundf(floatPoint_num * (1 << this->_fractional_bits));
	return ;
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPoint_num = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPoint_num);
}

void	Fixed::setRawBits( int const raw)
{
	this->_fixedPoint_num = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPoint_num / (float)(1 << this->_fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPoint_num >> this->_fractional_bits);	
}

std::ostream	&operator<<( std::ostream &obj, Fixed const &insert )
{
	obj << insert.toFloat();
	return (obj);
}
