/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:12:23 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 15:00:12 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	LOGC( GREEN ) << "MateriaSource default constructor.";

	for ( unsigned int i = 0; i < 4; i++ )
		this->_learned[ i ] = NULL;
}

MateriaSource::~MateriaSource( void ) {
	LOGC( RED ) << "MateriaSource destructor.";

	bool alreadyDeleted;

	for ( unsigned int i = 0; i < 4; i++ ) {
		alreadyDeleted = false;
		for ( unsigned int j = 0; j < 4; j++ ) {
			if ( this->_learned[ i ] && this->_learned[ i ] == this->_learned[ j ] && j < i )
				alreadyDeleted = true;
		}
		if ( this->_learned[ i ] && !alreadyDeleted ) {
			delete this->_learned[ i ];
		}
	}
}

MateriaSource::MateriaSource( MateriaSource const & other ) {
	LOGC( GREEN ) << "MateriaSource copy constructor.";

	for ( unsigned int i = 0; i < 4; i++ )
		this->_learned[ i ] = NULL;

	this->copyData( other );
}

MateriaSource& MateriaSource::operator=( MateriaSource const & other ) {
	LOGC( YELLOW ) << "MateriaSource assignation overload.";

	if ( this == &other )
		return ( *this );

	this->copyData( other );
	return ( *this );
}

void	MateriaSource::learnMateria( AMateria* m ) {
	int idx = -1;

	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( !this->_learned[ i ] && idx == -1 )
			idx = i;
	}
	if ( idx != -1 ) {
		LOGC( CYAN ) << "New Materia learn by MateriaSource " << this << ".";
		this->_learned[ idx ] = m;
	}
	else
		LOGC( CYAN ) << "MateriaSource " << this << " cant learn more AMateria.";
}

AMateria* MateriaSource::createMateria( std::string const & other ) {
	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( this->_learned[ i ] && this->_learned[ i ]->getType() == other )
			return ( this->_learned[ i ]->clone() );
	}
	return ( 0 );
}

void MateriaSource::copyData( MateriaSource const & other ) {
	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( this->_learned[ i ] )
			delete this->_learned[ i ];
	}

	AMateria const ** otherLearned = ( const AMateria** )other._learned;

	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( otherLearned[ i ] )
			this->_learned[ i ] = otherLearned[ i ]->clone();
	}
}
