/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:40:49 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/22 09:32:45 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/Log/Log.hpp"

template< typename T >
void	iter( T *array, size_t length, void ( *f )( T & ) ) {
	if ( !array || !f )
		return ;

	for ( size_t i = 0; i < length; i++ ) {
		f( array[ i ] );
	}
}

template< typename T >
void	iter( T *array, size_t length, void ( *f )( const T & ) ) {
	if ( !array || !f )
		return ;

	for ( size_t i = 0; i < length; i++ ) {
		f( array[ i ] );
	}
}

template< typename T >
void	display( T *array, size_t length, const std::string &desc ) {
	if ( !array )
		return ;

	Log	a = LOGC( DEBUG );

	a << desc;
	for ( size_t i = 0; i < length; i++ ) {
		a << array[ i ] << ( i < length -1 ? ", " : "" );
	}
}
