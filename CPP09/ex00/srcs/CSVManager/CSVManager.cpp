/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSVManager.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:21:49 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/29 16:24:31 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CSVManager.hpp"

CSVManager::CSVManager( void ) {}

CSVManager::CSVManager( const CSVManager &other ) : data( other.data ) {}

CSVManager::CSVManager( const std::string &filename, const char sep ) {
	std::ifstream	file( filename.c_str() );

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

		while ( std::getline( ss, cell, sep ) ) {
			if ( lineValueCount == 2 ) {
				// RAISE ERROR
			}
			if ( lineValueCount == 0 ) {
				date = cell;
			} else {
				int	price = atoi( cell.c_str() );

				if ( price < 0 ) {
					// RAISE ERROR
					continue ;
				}
				this->data[ date ] = price;
			}
			lineValueCount++;
		}
	}
	file.close();
}

CSVManager	&CSVManager::operator=( const CSVManager &other ) {
	this->data = other.data;

	return ( *this );
}

CSVManager::~CSVManager( void ) {}

std::map< std::string, int >	CSVManager::getData( void ) {
	return ( this->data );
}
