/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:25:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/15 16:20:53 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/proto.hpp"


static void	AddNumberCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK SPAN ADDNUMBER METHOD + DISPLAY MIN, MAX, SET";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Span	a( 5 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );

	a.display();
}

static void	AddNumbersCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK SPAN ADDNUMBERS METHOD + DISPLAY MIN, MAX, SET";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Span	a( 5 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.addNumber( rand() % 100 );
	a.display();

	std::cout << LEND << LEND;

	std::set< int >	toAdd;
	toAdd.insert( rand() % 100 );
	toAdd.insert( rand() % 100 );
	toAdd.insert( rand() % 100 );
	toAdd.insert( rand() % 100 );
	toAdd.insert( rand() % 100 );

	Span	b( 5 );
	b.addNumber( toAdd.begin(), toAdd.end() );
	b.display();
}

static void	AddTooManyNumbers( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK SPAN EXCEPTION WHEN ADDING TOO MANY NUMBERS";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	try {
		Span	a( 5 );
		a.addNumber( rand() % 100 );
		a.addNumber( rand() % 100 );
		a.addNumber( rand() % 100 );
		a.addNumber( rand() % 100 );
		a.addNumber( rand() % 100 );
		a.addNumber( rand() % 100 );
		a.display();
	} catch ( std::length_error &e ) {
		LOGC( CRITICAL ) << e.what();
	}
}

int	main( void ) {
	srand( time( NULL ) );
	AddNumberCheck();
	AddNumbersCheck();
	AddTooManyNumbers();
}
