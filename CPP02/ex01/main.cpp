/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/24 07:38:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed/Fixed.class.hpp"
#include <iostream>
#include <sstream>

int	main( void ) {
	Fixed 				a;
	Fixed 				const b( 10 );
	Fixed				const c( 42.42f );
	Fixed				const d( b );
	std::ostringstream	oss;

	a = Fixed( 1234.4321f );
	// Add to stream   |         Display Log         | Clear the stream
	oss << "a is " << a; log(std::cout, oss.str(), 0); oss.str("");
	oss << "b is " << b; log(std::cout, oss.str(), 0); oss.str("");
	oss << "c is " << c; log(std::cout, oss.str(), 0); oss.str("");
	oss << "d is " << d; log(std::cout, oss.str(), 0); oss.str("");
	oss << "a is " << a.toInt() << " as integer"; log(std::cout, oss.str(), 0); oss.str("");
	oss << "b is " << b.toInt() << " as integer"; log(std::cout, oss.str(), 0); oss.str("");
	oss << "c is " << c.toInt() << " as integer"; log(std::cout, oss.str(), 0); oss.str("");
	oss << "d is " << d.toInt() << " as integer"; log(std::cout, oss.str(), 0); oss.str("");
	return (0);
}
