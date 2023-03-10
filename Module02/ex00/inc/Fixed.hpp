/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:34:36 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/07 01:41:47 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPoint_num;
		static const int	_fractional_bits;

	public:
		Fixed( void );
		Fixed( Fixed const &src);
		
		~Fixed( void );

		Fixed	&operator=(Fixed const &rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
