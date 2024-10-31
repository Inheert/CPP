/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/30 14:22:24 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"
#include "iostream"

Fixed absolute(Fixed x) {
	return x < 0 ? x * -1 : x;
}

Fixed	squareRoot( Fixed x ) {
	if (x < 0)
		return (Fixed(-1));

	Fixed	estimation = x / 2.0f;
	Fixed	precision = Fixed(0.01f);

	while (absolute(estimation * estimation - x) > precision) {
		estimation = (estimation + x / estimation) / 2;
	}

	return (estimation);
}

Fixed	pythagore( Point a, Point b ) {
	Point	rightAngle = Point(a.getX().toFloat(), b.getY().toFloat());
	Fixed	distance = squareRoot(absolute(Fixed(a.getY() - b.getY()) + absolute(Fixed(a.getX() - b.getX()))));
	return (distance);
}

Fixed	triangleArea( Point const a, Point const b, Point const c ) {
	Fixed const	lengthAB = pythagore(a, b);
	Fixed const	lengthAC = pythagore(a, c);
	Fixed const	lengthBC = pythagore(b, c);

	std::cout << lengthAB << " - " << lengthAC << " - " << lengthBC << std::endl;

	Fixed const	semiPerimeter = (lengthAB + lengthAC + lengthBC) / 2;

	Fixed const	area = (squareRoot(semiPerimeter * (semiPerimeter - lengthAB) * (semiPerimeter - lengthBC) * (semiPerimeter - lengthAB)));
	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed const triangle = triangleArea(a, b, c);
	Fixed const littleTriangle1 = triangleArea(a, b, point);
	Fixed const littleTriangle2 = triangleArea(a, c, point);
	Fixed const littleTriangle3 = triangleArea(b, c, point);
	std::cout << triangle << " " << littleTriangle1 << " " << littleTriangle2 << " " << littleTriangle3 << std::endl;
	std::cout << triangle << "   " << (littleTriangle1 + littleTriangle2 + littleTriangle3) << std::endl;
	return (triangle == (littleTriangle1 + littleTriangle2 + littleTriangle3));
}

int	main( void ) {
	Point	a(2.0f, 3.0f);
	Point	b(5.0f, 7.0f);
	Point	c(6.0f, 3.0f);
	std::cout << bsp(a, b, c, Point(3.0f, 4.2f));
	return 0;
}
