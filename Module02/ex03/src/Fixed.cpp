/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:37 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/08 20:45:09 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

/* Constructors************************************************************** */

Fixed::Fixed( void ) : _fixedPoint_num( 0 )
{
	return ;
}

Fixed::Fixed( const int int_num )
{
	this->_fixedPoint_num = int_num << this->_fractional_bits;
	return ;
}

Fixed::Fixed( const float floatPoint_num )
{
	this->_fixedPoint_num = roundf(floatPoint_num * (1 << this->_fractional_bits));
	return ;
}

Fixed::Fixed( Fixed const &src )
{
	*this = src;
	return ;
}

/* Destructors*************************************************************** */

Fixed::~Fixed( void )
{
	return ;
}

/*  Setter & Getter********************************************************** */

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPoint_num);
}

void	Fixed::setRawBits( int const raw)
{
	this->_fixedPoint_num = raw;
}

/* Public Member Functions*************************************************** */

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPoint_num / (float)(1 << this->_fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPoint_num >> this->_fractional_bits);	
}

/* Assignment Operators****************************************************** */

Fixed	&Fixed::operator=( Fixed const &rhs )
{
	if (this != &rhs)
		this->_fixedPoint_num = rhs.getRawBits();
	return (*this);
}

/* Arithmetic Operators****************************************************** */

Fixed	Fixed::operator+( Fixed const &rhs ) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const &rhs ) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const &rhs ) const
{
	return Fixed( this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const &rhs ) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

/* Comparison Operators****************************************************** */

bool	Fixed::operator>( Fixed const &rhs ) const
{
	if (this->toFloat() > rhs.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<( Fixed const &rhs ) const
{
	if (this->toFloat() < rhs.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=( Fixed const &rhs ) const
{
	if (this->toFloat() >= rhs.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=( Fixed const &rhs ) const
{
	if (this->toFloat() <= rhs.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==( Fixed const &rhs ) const
{
	if (this->toFloat() == rhs.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=( Fixed const &rhs ) const
{
	if (this->toFloat() != rhs.toFloat())
		return (true);
	return (false);
}

/* Incremet / Decrement Operators******************************************** */

// Pre-Increment
Fixed	&Fixed::operator++( void )
{
	this->_fixedPoint_num++;
	return (*this);
}

// Post-Increment
Fixed	Fixed::operator++( int )
{
	Fixed	copy = *this;
	this->_fixedPoint_num++;
	return (copy);
}

// Pre-Decrement
Fixed	&Fixed::operator--( void )
{
	this->_fixedPoint_num--;
	return (*this);
}

// Post-Decrement
Fixed	Fixed::operator--( int )
{
	Fixed	copy = *this;
	this->_fixedPoint_num--;
	return (copy);
}

/* Public Overload Functions************************************************* */

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

/* Overload of the Insertion to Output Stream Object************************* */

std::ostream	&operator<<( std::ostream &obj, Fixed const &insert )
{
	obj << insert.toFloat();
	return (obj);
}
