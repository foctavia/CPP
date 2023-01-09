/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:48 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 00:03:26 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPoint_num;
		static const int	_fractional_bits;

	public:
	// Constructors
		Fixed( void );
		Fixed( const int int_num );
		Fixed( const float floatPoint_num );
		Fixed( Fixed const &src );

	// Destructor
		~Fixed( void );

	// Setter & Getter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	// Public Member Functions
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	// Overload Operators

		// Assignment Operator
		Fixed	&operator=( Fixed const &rhs );
	
		// Arithmetic Operators
		Fixed	operator+( Fixed const &rhs ) const;
		Fixed	operator-( Fixed const &rhs ) const;
		Fixed	operator*( Fixed const &rhs ) const;
		Fixed	operator/( Fixed const &rhs ) const;

		// Comparison Operators
		bool	operator>( Fixed const &rhs ) const;
		bool	operator<( Fixed const &rhs ) const;
		bool	operator>=( Fixed const &rhs ) const;
		bool	operator<=( Fixed const &rhs ) const;
		bool	operator==( Fixed const &rhs ) const;
		bool	operator!=( Fixed const &rhs ) const;

		// Increment / Decrement Operators
		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );
		
	// Public Overload Functions
		static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&max(Fixed const &fixed1, Fixed const &fixed2);
		
};

// Overload of the Insertion to Output Stream Object
std::ostream	&operator<<( std::ostream &obj, Fixed const &insert );

#endif
