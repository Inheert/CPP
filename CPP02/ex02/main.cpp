/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:03:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/23 09:05:18 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed/Fixed.hpp"
#include "iostream"


int	main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "1.  " << a << std::endl;
	std::cout << "2.  " << ++a << std::endl;
	std::cout << "3.  " << a << std::endl;
	std::cout << "4.  " << a++ << std::endl;
	std::cout << "5.  " << a << std::endl;
	std::cout << "6.  "<< b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
