/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/27 14:56:56 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"
#include "iostream"

Fixed	get_sign(Point const a, Point const b, Point const c) {
	return ((a.getX() - c.getX()) * (b.getY() - c.getY()) * (b.getX() - c.getX()) * (a.getY() - c.getY()));
} 

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed const	p1 = get_sign(point, a, b);
	Fixed const	p2 = get_sign(point, b, c);
	Fixed const	p3 = get_sign(point, c, a);

	std::cout << p1 << " " << p2 << " " << p3 << std::endl;
	bool	is_negative = (p1 < 0) || (p2 < 0) || (p3 < 0);
	bool	is_positive = (p1 > 0) || (p2 > 0) || (p3 > 0);
	return (!(is_negative && is_positive));
}

int	main( void ) {
	Point	a(1.0f, 1.0f);
	Point	b(3.5f, 3.0f);
	Point	c(5.5f, 1.0f);
	std::cout << bsp(a, b, c, Point(2.0f, 2.0f));
	return 0;
}
