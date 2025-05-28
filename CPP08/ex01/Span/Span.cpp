/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:25:51 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/28 14:56:52 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _size( 0 ) {

}

Span::Span( const unsigned int n ) :  _size( n ) {

}

Span::~Span( void ) {

}

Span::Span( const Span& other ) {
	this->_container = other._container;
}

Span&	Span::operator=( const Span& other ) {
	if ( this == &other )
		return ( *this );

	this->_container = other._container;
	return ( *this );
}

void	Span::addNumber( const int n ) {
	if ( this->_container.size() == this->_size ) {
		throw( std::length_error( "Span have reached its maximum capacity." ) );
		return ;
	}

	this->_container.insert( n );
}

void	Span::addNumber( std::set< int >::iterator begin, std::set< int >::iterator end ) {
	if ( this->_container.size() + std::distance( begin , end ) > this->_size ) {
		throw ( std::length_error( "The range to add is higher than the remaining space in the container." ) );
		return ;
	}

	while ( begin != end ) {
		this->_container.insert( *begin );
		begin++;
	}
}

int	Span::shortestSpan( void ) const {
	int	dist = std::numeric_limits< int >::max();
	std::set< int >::iterator last = this->_container.begin();

	for ( std::set< int >::iterator iter = last; iter != this->_container.end(); iter++ ) {
		dist = ( iter != last && *iter - *last < dist ) ? *iter - *last : dist;
		last = iter;
	}

	return ( dist );
}

int	Span::highestSpan( void ) const {
	return ( *( this->_container.rbegin() ) - *( this->_container.begin() ) );
}

void	Span::display( void ) const {
	Log	log = LOGC( INFO );
	log << "SPAN INFO" << LEND;
	log << "Size: " << this->_container.size() << ", max size: " << this->_size << LEND;
	log << "Shortest span: " << this->shortestSpan() << ", Highest span: " << this->highestSpan() << LEND;
	log << "Data:" << LEND;

	for ( std::set< int >::const_iterator iter = this->_container.begin(); iter != this->_container.end(); iter++ ) {
		log << *iter << ", ";
	}
}
