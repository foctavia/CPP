/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:42 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/08 22:33:37 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	isOnLine( Point p1, Point p2, Point cross )
{
	float	deltaX_cross = cross.getX().toFloat() - p1.getX().toFloat();
	float	deltaY_cross = cross.getY().toFloat() - p1.getY().toFloat();
	float	deltaX_line = p2.getX().toFloat() - p1.getX().toFloat();
	float	deltaY_line = p2.getY().toFloat() - p1.getY().toFloat();

	if ((deltaX_cross * deltaY_line) - (deltaY_cross * deltaX_line))
		return (false);
	return (true);
}

static float	getTriangleArea( Point const p1, Point const p2, Point const p3 )
{
	// area = ( x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) ) / 2
	
	float	triangleArea;

	triangleArea = ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) 
			+ (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()))
			+ (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())))
			/ 2;

	if (triangleArea <= 0)
		triangleArea *= -1;
	return (triangleArea);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	theTriangle = getTriangleArea(a, b, c);
	float	t1 = getTriangleArea(point, a, b);
	float	t2 = getTriangleArea(point, b, c);
	float	t3 = getTriangleArea(point, a, c);

	if (!t1 || !t2 || !t3 
		|| (a.getX().toFloat() == point.getX().toFloat() && a.getY().toFloat() == point.getY().toFloat())
		|| (b.getX().toFloat() == point.getX().toFloat() && b.getY().toFloat() == point.getY().toFloat())
		|| (c.getX().toFloat() == point.getX().toFloat() && c.getY().toFloat() == point.getY().toFloat())
		|| isOnLine(a, b, point)
		|| isOnLine(b, c, point)
		|| isOnLine(a, c, point))
		return (false);
	if (theTriangle == t1 + t2 + t3)
		return (true);
	return (false);
}
