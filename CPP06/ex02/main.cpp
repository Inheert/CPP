/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:54:25 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/20 10:44:48 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/Log/Log.hpp"
#include "Base/Base.hpp"
#include "A/A.hpp"
#include "B/B.hpp"
#include "C/C.hpp"

#include <cstdlib>
#include <iostream>

void	identify( Base *p ) {
	if ( dynamic_cast< A* >( p ) )
		LOGC( INFO ) << "This ptr is pointing a A class.";
	else if ( dynamic_cast< B* >( p ) )
		LOGC( INFO ) << "This ptr is pointing a B class.";
	else if ( dynamic_cast< C* >( p ) )
		LOGC( INFO ) << "This ptr is pointing a C class.";
}

void	identify( Base &r ) {
	try {
		( void )dynamic_cast< A& >( r );
		LOGC( DEBUG ) << "This ptr is pointing a A class.";
	}
	catch ( std::exception &e ) {}

	try {
		( void )dynamic_cast< B& >( r );
		LOGC( DEBUG ) << "This ptr is pointing a B class.";
	}
	catch ( std::exception &e ) {}

	try {
		( void )dynamic_cast< C& >( r );
		LOGC( DEBUG ) << "This ptr is pointing a C class.";
	}
	catch ( std::exception &e ) {}
}

Base	*generate( void ) {

	switch ( rand() % 3 ) {
		case ( 0 ) : { return ( new A() ); }
		case ( 1 ) : { return ( new B() ); }
		case ( 2 ) : { return ( new C() ); }
	}
	return ( NULL );
}

int main( void ) {
	srand( time( NULL ) );

	for ( unsigned int i = 0; i < 15; ++i ) {
		std::cout << ".                                     ." << LEND;
		Base	*tmp = generate();
		identify( tmp );
		identify( *tmp );
		delete tmp;
	}
}
