/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/06 07:49:37 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void ) {
	Point	a(2.0f, 3.0f);
	Point	b(5.0f, 7.0f);
	Point	c(6.0f, 3.0f);
	std::cout << bsp(a, b, c, Point(4.0f, 3.0f));
	return 0;
}
