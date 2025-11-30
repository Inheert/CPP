/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:32:35 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/30 18:09:36 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream	file( "data.csv" );

	if ( !file.is_open() ) {
		LOGC( CRITICAL ) << "Error: cannot open the file => " << "data.csv";
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
				this->_data[ date ] = std::strtod( cell.c_str(), NULL );
			}
			lineValueCount++;
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) {
	this->_data = other._data;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &other ) {
	if ( this == &other )
		return ( *this );

	this->_data = other._data;
	return ( *this );
}

BitcoinExchange::~BitcoinExchange( void ) {}

std::string BitcoinExchange::_trim( const std::string &s ) {

	size_t start = s.find_first_not_of( " \t" );
	size_t end = s.find_last_not_of( " \t" );

	if ( start == std::string::npos ) {
		return ( "" );
	}
	return ( s.substr( start, end - start + 1 ) );
}

static bool isLeapYear( int year ) {
	if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) ) {
		return ( true );
	}
	return ( false );
}

bool BitcoinExchange::_isValidDate( const std::string &date ) {

	if ( date.size() != 10 || date[ 4 ] != '-' || date[ 7 ] != '-' ) {
		return ( false );
	}
	std::string year_str = date.substr( 0, 4 );
	std::string month_str = date.substr( 5, 2 );
	std::string day_str = date.substr( 8, 2 );

	int year = atoi( year_str.c_str() );
	int month = atoi( month_str.c_str() );
	int day = atoi( day_str.c_str() );

	if ( month < 1 || month > 12 ) {
		return ( false );
	}
	if ( day < 1 || day > 31 ) {
		return ( false );
	}
	int daysInMonth[] = { 31, ( isLeapYear( year ) ? 29 : 28 ), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ( day > daysInMonth[ month - 1 ] ) {
		return ( false );
	}
	return ( true );
}

void	BitcoinExchange::execute( const std::string &filename ) {
	std::ifstream	file( filename.c_str() );

	if ( !file.is_open() ) {
		// RAISE ERROR
		LOGC( CRITICAL ) << "Error: cannot open the file => " << filename;
		return ;
	}

	std::string	line;

	std::getline( file, line );
	line = this->_trim( line );

	if ( line != "date | value" ) {
		LOGC( CRITICAL ) << "Error: header invalid.";
		return ;
	}

	while ( std::getline( file, line ) ) {
		std::stringstream			ss( line );
		std::string					date;
		double						quantity;
		char						*invalidChar;

		if ( line.empty() )
			continue ;

		size_t	delimiter = line.find( '|' );

		if ( delimiter == std::string::npos ) {
			LOGC( CRITICAL ) << "Error: bad input => " << line;
			continue ;
		}

		date = this->_trim( line.substr( 0, delimiter ) );
		quantity = std::strtod( this->_trim( line.substr( delimiter + 1 ) ).c_str(), &invalidChar );

		if ( std::strcmp( invalidChar, "" ) ) {
			LOGC( CRITICAL ) << "Error: non numerical char found in the price.";
			continue ;
		}

		if ( quantity < 0 ) {
			LOGC( CRITICAL ) << "Error: not a positive number.";
			continue ;
		} else if ( quantity > 1000 ) {
			LOGC( CRITICAL ) << "Error: too large a number.";
			continue ;
		}

		std::map< std::string, double >::iterator	it = this->_data.upper_bound( date );
		if ( it != this->_data.begin() ) {
			it--;
		}

		LOGC( INFO ) << date << " => " << quantity << " = " << ( it->second * quantity );
	}

	file.close();
}
