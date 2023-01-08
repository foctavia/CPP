/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:50 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/08 22:53:05 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
		
	public:
		Point( void );
		Point( const float floatX, const float floatY);
		Point( Point const &src);
		
		~Point( void );

		Point	&operator=( Point const &rhs );
		
		const Fixed	getX( void ) const;
		const Fixed	getY( void ) const;

};

bool			bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream	&operator<<( std::ostream &obj, Point const &insert );

#endif
