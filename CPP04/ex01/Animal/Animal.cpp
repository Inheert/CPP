/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 09:11:18 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "Animal" ) {
	LOGC( GREEN ) << "Animal default constructor.";
}


Animal::~Animal( void ) {
	LOGC( RED ) << "Animal destructor.";
}

Animal::Animal( const std::string type ) : _type( type ) {
	LOGC( GREEN ) << "Animal constructor.";
}

Animal::Animal( const Animal &other ) {
	this->_type = other._type;

	LOGC( GREEN ) <<"Animal copy constructor.";
}

Animal	&Animal::operator=( const Animal &other ) {
	LOGC( YELLOW ) << "Animal assignation overload called.";

	this->_type = other._type;

	return ( *this );
}

void	Animal::setType( const std::string newType ) {
	this->_type = newType;
}

std::string	Animal::getType( void ) const {
	return ( this->_type );
}

void	Animal::makeSound( void ) const {
	LOG() << "I need to be a specific animal to make sound.";
}

Brain	*Animal::getBrain( void ) const {
	return ( NULL );
}
