/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 14:21:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "Animal" ) {
	LOGC( GREEN ) << "AAnimal default constructor.";
}


AAnimal::~AAnimal( void ) {
	LOGC( RED ) << "AAnimal destructor.";
}

AAnimal::AAnimal( const std::string type ) : _type( type ) {
	LOGC( GREEN ) << "AAnimal constructor.";
}

AAnimal::AAnimal( const AAnimal &other ) {
	this->_type = other._type;

	LOGC( GREEN ) <<"AAnimal copy constructor.";
}

AAnimal	&AAnimal::operator=( const AAnimal &other ) {
	LOGC( YELLOW ) << "AAnimal assignation overload called.";

	this->_type = other._type;

	return ( *this );
}

void	AAnimal::setType( const std::string newType ) {
	this->_type = newType;
}

std::string	AAnimal::getType( void ) const {
	return ( this->_type );
}

void	AAnimal::makeSound( void ) const {
	LOG() << "I need to be a specific animal to make sound.";
}

Brain	*AAnimal::getBrain( void ) const {
	return ( NULL );
}
