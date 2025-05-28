/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:25:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/28 14:55:39 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/proto.hpp"

void	AddNumberCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK SPAN ADDNUMBER METHOD + DISPLAY MIN, MAX, SET";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Span	a( 5 );
	a.addNumber( 1 );
	a.addNumber( 6 );
	a.addNumber( 3 );
	a.addNumber( 4 );
	a.addNumber( 5 );

	LOG() << a.shortestSpan();
	LOG() << a.highestSpan();
	a.display();
}

void	AddNumbersCheck( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK SPAN ADDNUMBERS METHOD + DISPLAY MIN, MAX, SET";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Span	a( 5 );
	a.addNumber( 1 );
	a.addNumber( 6 );
	a.addNumber( 3 );
	a.addNumber( 4 );
	a.addNumber( 5 );
	a.display();

	std::cout << LEND << LEND;

	std::set< int >	toAdd;
	toAdd.insert( 1 );
	toAdd.insert( 6 );
	toAdd.insert( 3 );
	toAdd.insert( 4 );
	toAdd.insert( 5 );

	Span	b( 5 );
	b.addNumber( toAdd.begin(), toAdd.end() );
	b.display();
}

int	main( void ) {
	AddNumberCheck();
	AddNumbersCheck();
}
