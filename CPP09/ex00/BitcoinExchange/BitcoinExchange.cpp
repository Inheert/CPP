/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:32:35 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/28 14:31:06 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream	file( "data.csv" );

	if ( !file.is_open() ) {
		// RAISE ERROR
		return ;
	}

	std::string	line;
	bool		firstLine = true;
	while ( std::getline( file, line ) ) {
		if ( firstLine ) {
			firstLine = false;
			continue ;
		}

		std::stringstream			ss( line );
		std::string					cell;
		std::string					date;
		int							lineValueCount = 0;

		while ( std::getline( ss, cell, ',' ) ) {
			if ( lineValueCount == 0 ) {
				date = cell;
			} else {
				int	price = atoi( cell.c_str() );
				this->data[ date ] = price;
				LOGC( INFO ) << date << ", " << this->data[ date ];
			}
			lineValueCount++;
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) {
	this->data = other.data;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &other ) {
	if ( this == &other )
		return ( *this );

	this->data = other.data;
	return ( *this );
}

BitcoinExchange::~BitcoinExchange( void ) {}
