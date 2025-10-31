/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:55:37 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/31 13:32:54 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template< typename T >
MutantStack< T >::MutantStack( void ) : std::stack< T >() {}

template< typename T >
MutantStack< T >::MutantStack( const MutantStack &other ) : std::stack< T >( other ) {}

template< typename T >
MutantStack< T >	&MutantStack< T >::operator=( const MutantStack &other ) {
	if  ( this == other )
		return ( *this );

	this->std::stack< T >::operator=( other );

	return ( *this );
}

template< typename T >
MutantStack< T >::~MutantStack( void ) {}

template< typename T >
typename MutantStack< T >::iterator MutantStack< T >::begin( void ) {
	return ( this->std::stack< T >::c.begin() );
}

template< typename T >
typename MutantStack< T >::iterator MutantStack< T >::end( void ) {
	return ( this->std::stack< T >::c.end() );
}

template< typename T >
typename MutantStack< T >::const_iterator MutantStack< T >::begin( void ) const {
	return ( this->std::stack< T >::c.begin() );
}

template< typename T >
typename MutantStack< T >::const_iterator MutantStack< T >::end( void ) const {
	return ( this->std::stack< T >::c.end() );
}

template< typename T >
typename MutantStack< T >::reverse_iterator MutantStack< T >::rbegin( void ) {
	return ( this->std::stack< T >::c.rbegin() );
}

template< typename T >
typename MutantStack< T >::reverse_iterator MutantStack< T >::rend( void ) {
	return ( this->std::stack< T >::c.rend() );
}

template< typename T >
typename MutantStack< T >::const_reverse_iterator MutantStack< T >::rbegin( void ) const {
	return ( this->std::stack< T >::c.rbegin() );
}

template< typename T >
typename MutantStack< T >::const_reverse_iterator MutantStack< T >::rend( void ) const {
	return ( this->std::stack< T >::c.rend() );
}
