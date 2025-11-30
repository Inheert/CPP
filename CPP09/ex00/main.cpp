/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:15:14 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/30 19:12:58 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"

int	main( int argc, char **argv ) {
	if ( argc <= 1 )
		return ( 1 );
	BitcoinExchange	input;
	input.execute( argv[ 1 ] );

	// std::map< std::string, int > data = input.getData();
	// // std::string::find_first_not_of(  )
	// for ( std::map< std::string, int >::iterator it = data.begin(); it != data.end(); it++ ) {
	// 	LOGC( INFO ) << it->first << ", " << it->second;
	// }
}

