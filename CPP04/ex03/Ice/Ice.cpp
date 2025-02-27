/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:56:50 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 13:45:44 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" ) {
	LOGC( GREEN ) << "Ice default constructor.";
}

Ice::~Ice( void ) {
	LOGC( RED ) << "Ice destructor.";
}

Ice::Ice( Ice const & other ) : AMateria( other ) {
	LOGC( GREEN ) << "Ice copy constructor.";
}

Ice&	Ice::operator=( Ice const & other ) {
	LOGC( YELLOW ) << "Ice assignation overload.";

	if ( this == &other )
		return ( *this );

	AMateria::operator=( other );
	return ( *this );
}

AMateria*	Ice::clone( void ) const {
	return ( new Ice( *this ) );
}

void	Ice::use( ICharacter& target ) {
	MSG() << "* shoots an ice bolt at " << target.getName() << " *";
}
