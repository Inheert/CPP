/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:38:41 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/20 11:30:47 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/proto.hpp"
#include <cstdlib>
#include <iostream>

int	main( void ) {
	LOGFLAGS( FL_NONE );

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "SWAP CHECK.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;


	int a = 45; int b = 12;
	LOGC( DEBUG ) << "a = " << a << ", b = " << b;
	swap( a, b );
	LOGC( DEBUG ) << "a = " << a << ", b = " << b;

	std::string c = "wdok"; std::string d = "opt";
	LOGC( DEBUG ) << "c = " << c << ", d = " << d;
	swap( c, d );
	LOGC( DEBUG ) << "c = " << c << ", d = " << d;

	Example	e; Example f( "CustomName" );
	LOGC( DEBUG ) << "e = " << e << ", f = " << f;
	swap( e, f );
	LOGC( DEBUG ) << "e = " << e << ", f = " << f;

	bool g = true; bool h = false;
	LOGC( DEBUG ) << "g = " << g << ", h = " << h;
	swap( g, h );
	LOGC( DEBUG ) << "g = " << g << ", h = " << h;

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "INT MINUS AND MAX CHECK.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( unsigned int i = 0; i < 15; i++ ) {
		int	n = rand();
		int	m = rand();
		int	minus = min( n, m );
		int	maximum = max( n, m );
		LOGC( INFO ) << "First int: " << n << " (" << &n << "), second int: " << m << "(" << &m << ")";
		LOGC( DEBUG ) << "Minimum: " << minus << ", maximum: " << maximum << ".";
	}

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "FLOAT MINUS AND MAX CHECK.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( unsigned int i = 0; i < 15; i++ ) {
		float	n = ( float )rand() / ( float )rand();
		float	m = ( float )rand() / ( float )rand();
		float	minus = min( n, m );
		float	maximum = max( n, m );
		LOGC( INFO ) << "First int: " << n << " (" << &n << "), second int: " << m << "(" << &m << ")";
		LOGC( DEBUG ) << "Minimum: " << minus << ", maximum: " << maximum << ".";
	}
}
