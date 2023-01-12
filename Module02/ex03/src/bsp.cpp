/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:50:42 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/12 15:50:27 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// source : https://codereview.stackexchange.com/questions/98787/checking-if-the-point-is-on-the-line-segment
static bool	isOnLine( Point start, Point end, Point point )
{
	float	deltaX_line = end.getX().toFloat() - start.getX().toFloat();
	float	deltaY_line = end.getY().toFloat() - start.getY().toFloat();
	float	deltaX_point = point.getX().toFloat() - start.getX().toFloat();
	float	deltaY_point = point.getY().toFloat() - start.getY().toFloat();

	return ((deltaX_point * deltaY_line) == (deltaY_point * deltaX_line));
}

// source : https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
static float	getTriangleArea( Point const p1, Point const p2, Point const p3 )
{
	float	triangleArea;

	// area = ( x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) ) / 2
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
