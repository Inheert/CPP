/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:49:16 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 05:13:10 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "default" ) {
	LOGC( GREEN ) << "WrongAnimal default constructor.";
}

WrongAnimal::~WrongAnimal( void ) {
	LOGC( RED ) << "WrongAnimal destructor.";
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	LOGC( GREEN ) << "WrongAnimal constructor.";
}

WrongAnimal::WrongAnimal( WrongAnimal const &other ) : _type( other.getType() ) {
	LOGC( GREEN ) << "WrongAnimal copy constructor.";
}

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const &other ) {
	LOGC( YELLOW ) << "WrongAnimal assignation overload.";
	this->_type = other.getType();

	return ( *this );
}

std::string	WrongAnimal::getType( void ) const {
	return ( this->_type );
}

void	WrongAnimal::makeSound( void ) const {
	LOG() << "Am i so i be to have to be";
}
