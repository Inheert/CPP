/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:18:01 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 13:44:41 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" ) {
	LOGC( GREEN ) << "Cure default constructor.";
}

Cure::~Cure( void ) {
	LOGC( RED ) << "Cure destructor.";
}

Cure::Cure( Cure const & other ) : AMateria( other ) {
	LOGC( GREEN ) << "Cure copy constructor.";
}

Cure&	Cure::operator=( Cure const & other ) {
	LOGC( YELLOW ) << "Cure assignation overload";

	if ( this == &other )
		return ( *this );

	AMateria::operator=( other );
	return ( *this );
}

AMateria*	Cure::clone( void ) const {
	return ( new Cure( *this ) );
}

void	Cure::use( ICharacter& target ) {
	MSG() << "* heals " << target.getName() << "'s wounds *";
}
