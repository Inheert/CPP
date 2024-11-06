/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 07:40:15 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/06 07:44:04 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"
#include "iostream"
#include <iomanip>

Fixed absolute(Fixed x) {
	return x < 0 ? x * -1 : x;
}

Fixed	triangleArea( Point const a, Point const b, Point const c ) {
	Fixed areaABC = absolute((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0f);
	return (areaABC);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed const triangle = triangleArea(a, b, c);
	Fixed const littleTriangle1 = triangleArea(a, b, point);
	Fixed const littleTriangle2 = triangleArea(a, c, point);
	Fixed const littleTriangle3 = triangleArea(b, c, point);
	std::cout << triangle << " " << littleTriangle1 << " " << littleTriangle2 << " " << littleTriangle3 << std::endl;
	std::cout << triangle << "   " << (littleTriangle1 + littleTriangle2 + littleTriangle3) << std::endl;

	if (littleTriangle1 == 0 || littleTriangle2 == 0 || littleTriangle3 == 0)
		return (false);

	const float	epsilon = 0.00001f;
	return (std::fabs(triangle.toFloat() - (littleTriangle1.toFloat() + littleTriangle2.toFloat() + littleTriangle3.toFloat())) < epsilon);
}
