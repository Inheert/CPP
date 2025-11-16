/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openCSV.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:15:11 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/16 19:30:09 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"

std::vector< std::vector< std::string > > readCSV( const std::string &filename, const char &c ) {
	std::vector< std::vector< std::string > >	data;
	std::ifstream								file( filename.c_str() );

	if ( !file.is_open() ) {
		LOGC( CRITICAL ) << "Failed to pen file: " << filename;
		return data;
	}

	std::string	line;
	while ( std::getline( file, line ) ) {
		std::vector< std::string > 	row;
		std::stringstream			ss( line );
		std::string					cell;

		while ( std::getline( ss, cell, c ) ) {
			row.push_back( cell );
		}

		data.push_back( row );
	}

	file.close();
	return ( data );
}
