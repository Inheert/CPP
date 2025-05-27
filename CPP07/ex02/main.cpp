/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:21:40 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/27 08:39:56 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/proto.hpp"

void	NullArrayCheck( void ) {
	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "NULL ARRAY CREATION";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Array< int >	a;
	Array< char >	b;
	Array< char* >	c;
	Array< Array<float  > > d;
}

void	EmptyArrayCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "EMPTY ARRAY CREATION";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Array< int >	a( rand() % 20 );
	Array< char >	b( rand() % 20 );
	Array< char* >	c( rand() % 20 );
	Array< Array< float > > d( rand() % 20 );
}

void	FilledArrayCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "FILLED ARRAY CREATION";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	DISABLE_DEBUG();

	unsigned int	size = rand() % 10;
	Array< int >	a( size );
	for ( unsigned int i = 0; i < size; i++ ) {
		a[ i ] = rand() % INT32_MAX;
	}
	a.display();

	size =	rand() % 10;
	Array< char >	b( size );
	for ( unsigned int i = 0; i < size; i++ ) {
		b[ i ] = rand() % 128;
	}
	b.display();

	size = rand() % 10;
	Array< char** >	c( size );
	c.display();

	size = rand() % 10;
	Array< Array< float > > d( size );
	for ( unsigned int i = 0; i < size; i++ ) {
		unsigned int	listSize = rand() % 5;
		d[ i ] = Array< float >( listSize );
		for ( unsigned int j = 0; j < listSize; j++ ) {
			d[ i ][ j ] = rand() % INT32_MAX;
		}
		d[ i ].display();
	}
	d.display();
}

void	OutOfRangeCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "OUT OF RANGE ARRAY CREATION";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	ENABLE_DEBUG();

	Array< int >	a( 10 );
	try {
		a[ 11 ] = 5;
	}
	catch ( std::exception &e ) {
		LOGC( CRITICAL ) << e.what();
	}
	try {
		a[ -1 ] = 5;
	}
	catch ( std::exception &e ) {
		LOGC( CRITICAL ) << e.what();
	}
}

int	main( void ) {
	srand( time( NULL ) );

	NullArrayCheck();
	EmptyArrayCheck();
	FilledArrayCheck();
	OutOfRangeCheck();
}
