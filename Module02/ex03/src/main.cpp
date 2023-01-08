/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:34 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/08 22:57:30 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main( void )
{
	Point const	a;
	Point const	b(10,30);
	Point const	c(20, 0);

	std::cout << "point A( " << a.getX().toFloat() << "," << a.getY().toFloat() << " )" << std::endl
		<< "point B( " << b.getX().toFloat() << "," << b.getY().toFloat() << " )" << std::endl
		<< "point C( " << c.getX().toFloat() << "," << c.getY().toFloat() << " )" << std::endl << std::endl;

	Point	*points = new Point[5];
	
	points[0] = Point(0, 0);
	points[1] = Point(10, 5);
	points[2] = Point(0, 30);
	points[3] = Point(40, 15);
	points[4] = Point(-25, -15);

	for (int i = 0; i < 5; i++)
	{
		std::cout << "point X( " << points[i].getX().toFloat() << "," << points[i].getY().toFloat() << " )";
		if (bsp(a, b, c, points[i]))
			std::cout << " is inside triangle A, B, C." << std::endl;
		else
			std::cout << " is NOT inside triangel A, B, C." << std::endl;
	}
	
	delete [] points;
	return 0;
}
