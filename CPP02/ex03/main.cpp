/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/20 10:38:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"
#include <sstream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void ) {
	Point				a(2.0f, 3.0f);
	Point				b(5.0f, 7.0f);
	Point				c(6.0f, 3.0f);
	std::ostringstream	oss;

	oss << bsp(a, b, c, Point(4.0f, 3.0f)); log(std::cout, oss.str(), 0); oss.str();
	return 0;
}
