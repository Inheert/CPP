/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:01:27 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 13:18:33 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name( "defaultName" ) {
	LOGC( GREEN ) << "Character default constructor";

	for ( unsigned int i = 0; i < 4; i++ )
		this->_inventory[ i ] = NULL;
}

Character::~Character( void ) {
	LOGC( RED ) << "Character destructor.";

	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( this->_inventory[ i ] )
			delete this->_inventory[ i ];
	}
}

Character::Character( std::string const name ) : _name( name ) {
	LOGC( GREEN ) << "Character constructor.";

	for ( unsigned int i = 0; i < 4; i++ )
		this->_inventory[ i ] = NULL;
}

Character::Character( Character const & other ) {
	LOGC( GREEN ) << "Character copy constructor.";

	for ( unsigned int i = 0; i < 4; i++ )
		this->_inventory[ i ] = NULL;

	this->copyData( other );
}

Character& Character::operator=( Character const & other ) {
	LOGC( YELLOW ) << "Character assignation overload.";

	if ( this == &other )
		return ( *this );

	this->copyData( other );
	return ( *this );
}

std::string const & Character::getName( void ) const {
	return ( this->_name );
}

AMateria** Character::getInventory( void ) const {
	return ( ( AMateria** )this->_inventory );
}


void Character::copyData( Character const & other ) {
	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( this->_inventory[ i ] )
			delete this->_inventory[ i ];
	}

	this->_name = other._name;
	AMateria** otherInventory = other.getInventory();

	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( otherInventory[ i ] )
			this->_inventory[ i ] = otherInventory[ i ]->clone();
	}
}

void Character::equip( AMateria* m ) {
	int idx = -1;

	for ( unsigned int i = 0; i < 4; i++ ) {
		if ( m == this->_inventory[ i ] ) {
			return ;
		}
		if ( !this->_inventory[ i ] && idx == -1 )
			idx = i;
	}
	if ( idx != -1 )
		this->_inventory[ idx ] = m;
}

void Character::unequip( int idx ) {
	if (idx < 0 || idx > 3)
		return ;

	this->_inventory[ idx ] = NULL;
}

void Character::use( int idx,ICharacter& target ) {
	if ( idx < 0 || idx > 3 || !this->_inventory[ idx ] )
		return ;

	this->_inventory[ idx ]->use( target );
}
