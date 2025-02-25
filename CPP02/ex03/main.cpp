/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/24 08:32:24 by tclaereb         ###   ########.fr       */
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

	oss << bsp(a, b, c, Point(4.0f, 3.0f)); log(std::cout, oss.str(), 0); oss.str("");
	oss << bsp(a, b, c, Point(2.0f, 3.0f)); log(std::cout, oss.str(), 0); oss.str("");
	oss << bsp(a, b, c, Point(8.0f, 3.0f)); log(std::cout, oss.str(), 0); oss.str("");
	oss << bsp(a, b, c, Point(1.0f, 6.0f)); log(std::cout, oss.str(), 0); oss.str("");
	oss << bsp(a, b, c, Point(4.0f, 4.0f)); log(std::cout, oss.str(), 0); oss.str("");
	oss << bsp(a, b, c, Point(5.0f, 5.0f)); log(std::cout, oss.str(), 0); oss.str("");
	return 0;
}
