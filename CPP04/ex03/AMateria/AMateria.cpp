/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:19:45 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 14:03:55 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "none" ) {
	LOGC( GREEN ) << "AMateria default constructor.";
}

AMateria::~AMateria( void ) {
	LOGC( RED ) << "AMateria destructor.";
}

AMateria::AMateria( std::string const & type ) : _type( type ) {
	LOGC( GREEN ) << "AMaterial constructor.";
}

AMateria::AMateria( AMateria const & other ) : _type( other._type ) {
	LOGC( GREEN ) << "AMateria copy constructor.";
}

AMateria&	AMateria::operator=( AMateria const & other ) {
	LOGC( YELLOW ) << "AMateria assignation overload.";
	if ( this == &other )
		return ( *this );

	this->_type = other._type;
	return ( *this );
}

std::string const & AMateria::getType( void ) const {
	return ( this->_type );
}

void	AMateria::use( ICharacter& target ) {
	(void)target;
}
