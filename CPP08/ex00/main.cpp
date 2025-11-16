/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:41:16 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/13 12:35:50 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/proto.hpp"


void	CheckIndex( int idx, int v ) {
	if ( idx == -1 )
		LOGC( WARNING ) << "'" << v << "' doesn't exist in array.";
	else
		LOGC( SUCCESS ) << "'" << v << "' have been found at index: " << idx;
}

int	main( void ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK WITH VECTOR";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	std::vector< int > vec;
	vec.push_back( 4 );
	vec.push_back( 45 );
	vec.push_back( 81 );
	vec.push_back( 1 );
	vec.push_back( 4 );

	displayContainer( vec );
	CheckIndex( easyfind( vec, 4 ), 4 );
	CheckIndex( easyfind( vec, 1 ), 1 );
	CheckIndex( easyfind( vec, 40 ), 40 );

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK WITH DEQUE";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	std::deque< int > deq;

	deq.push_back( 1 );
	deq.push_back( 145 );
	deq.push_back( 84 );
	deq.push_back( 65 );
	deq.push_front( 1 );
	deq.push_back( 51 );

	displayContainer( deq );
	CheckIndex( easyfind( deq, 1 ), 1 );
	CheckIndex( easyfind( deq, 145 ), 145 );
	CheckIndex( easyfind( deq, 88 ), 88 );

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "CHECK WITH LIST";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	std::list< int > lst;

	lst.push_back( 71 );
	lst.push_back( 782 );
	lst.push_back( 368 );
	lst.push_back( 12 );
	lst.push_front( 782 );
	lst.push_back( 1 );

	displayContainer( lst );
	CheckIndex( easyfind( lst, 782 ), 782 );
	CheckIndex( easyfind( lst, 12 ), 12 );
	CheckIndex( easyfind( lst, 111 ), 111 );
}
