/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:40:43 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/21 15:05:08 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/iter.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

void	toLower( char &c ) {
	c = std::tolower( static_cast< unsigned char >( c ) );
}

void	toUpper( char &c ) {
	c = std::toupper( static_cast< unsigned char >( c ) );
}

void	powerOfFive( int &n ) {
	int tmp = n;

	for ( unsigned int i = 0; i < 4; i++ ) {
		tmp = tmp * n;
	}
	n = tmp;
}

void	arrayValueSwap( int *arr ) {
	int	tmp = arr[ 0 ];
	arr[ 0 ] = arr[ 1 ];
	arr[ 1 ] = tmp;
}

void	charArrayCheck( void ) {
	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "ITER CHECK ON CHAR ARRAY ( TOLOWER AND TOUPPER ).";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	char	arr[] = { 'a', 'b', 'c' };
	size_t		len = sizeof( arr ) / sizeof( char );

	display( arr, len, "Array: " );
	iter( arr, len, toUpper );
	display( arr, len, "Array after iter: " );
	iter( arr, len, toLower );
	display( arr, len, "Array after iter again: " );
}

void	intArrayCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "ITER CHECK ON INT ARRAY ( POWER OF 5 ).";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	int	arr[] = { 3, 5, 7 };
	size_t	len = sizeof( arr ) / sizeof( int );

	display( arr, len, "Array: " );
	iter( arr, len, powerOfFive );
	display( arr, len, "Array after iter: " );
}

int	main( void ) {
	charArrayCheck();
	intArrayCheck();
}
