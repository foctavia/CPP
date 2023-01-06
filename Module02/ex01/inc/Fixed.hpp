/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:42:29 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/06 18:27:46 by foctavia         ###   ########.fr       */
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
		static const int	_fractionalional_bits;

	public:
		Fixed( void );
		Fixed( const int int_num );
		Fixed( const float floatPoint_num );
		Fixed( Fixed const &src);
		~Fixed( void );

		Fixed	&operator=( Fixed const &rhs );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

std::ostream	&operator<<( std::ostream &obj, Fixed const &insert );

#endif