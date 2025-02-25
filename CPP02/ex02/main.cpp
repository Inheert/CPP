/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/24 07:46:38 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed/Fixed.hpp"
#include <iostream>
#include <sstream>

int	main( void ) {
	Fixed				a;
	Fixed const			b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed				c(5);
	std::ostringstream	oss;

	oss << a; log(std::cout, oss.str(), 0); oss.str("");
	oss << ++a; log(std::cout, oss.str(), 0); oss.str("");
	oss << a; log(std::cout, oss.str(), 0); oss.str("");
	oss << a++; log(std::cout, oss.str(), 0); oss.str("");
	oss << a; log(std::cout, oss.str(), 0); oss.str("");
	oss << b; log(std::cout, oss.str(), 0); oss.str("");
	oss << Fixed::max(a, b); log(std::cout, oss.str(), 0); oss.str("");

	std::cout << ++c;

	return (0);
}
