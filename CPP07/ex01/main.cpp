/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:40:43 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/30 09:29:45 by tclaereb         ###   ########.fr       */
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

void	printElement( const char &str ) {
	std::cout << str << ", ";
}


void	charArrayCheck( void ) {
	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "ITER CHECK ON CHAR ARRAY ( TOLOWER AND TOUPPER ).";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	char	arr[] = { 'a', 'b', 'c' };
	size_t		len = sizeof( arr ) / sizeof( char );

	display( arr, len, "Array: " );
	iter( arr, len, toUpper );
	display( arr, len, "Array after iter (to upper applied): " );
	iter( arr, len, toLower );
	display( arr, len, "Array after iter again (to lower applied): " );
	LOGC( DEBUG ) << "iter using a const value as func arg:";
	iter( arr, len, printElement );
}

void	intArrayCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "ITER CHECK ON INT ARRAY ( POWER OF 5 ).";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	int	arr[] = { 3, 5, 7 };
	size_t	len = sizeof( arr ) / sizeof( int );

	display( arr, len, "Array: " );
	iter( arr, len, powerOfFive );
	display( arr, len, "Array after iter (power of 5 applied): " );
}

int	main( void ) {
	charArrayCheck();
	intArrayCheck();
}
