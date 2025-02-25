/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 09:33:19 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal( void ) : _type( "Animal" ) {
	LOGC( GREEN ) << "A_Animal default constructor.";
}


A_Animal::~A_Animal( void ) {
	LOGC( RED ) << "A_Animal destructor.";
}

A_Animal::A_Animal( const std::string type ) : _type( type ) {
	LOGC( GREEN ) << "A_Animal constructor.";
}

A_Animal::A_Animal( const A_Animal &other ) {
	this->_type = other._type;

	LOGC( GREEN ) <<"A_Animal copy constructor.";
}

A_Animal	&A_Animal::operator=( const A_Animal &other ) {
	LOGC( YELLOW ) << "A_Animal assignation overload called.";

	this->_type = other._type;

	return ( *this );
}

void	A_Animal::setType( const std::string newType ) {
	this->_type = newType;
}

std::string	A_Animal::getType( void ) const {
	return ( this->_type );
}

void	A_Animal::makeSound( void ) const {
	LOG() << "I need to be a specific animal to make sound.";
}

Brain	*A_Animal::getBrain( void ) const {
	return ( NULL );
}
