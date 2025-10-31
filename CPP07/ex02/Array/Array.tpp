/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:29:07 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/30 10:23:39 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template< class T >
struct is_pointer { static const bool value = false; };

template< class T >
struct is_pointer< T* > { static const bool value = true; };

template< class T >
struct is_pointer< T* const > { static const bool value = true; };

template< class T >
struct is_pointer< T* volatile > { static const bool value = true; };

template< class T >
struct is_pointer< T* const volatile > { static const bool value = true; };

template< typename T >
Array< T >::Array( void ) : _arr( NULL ), _size( 0 ) {
	LOGC( DEBUG ) << "Array default constructor called for type " << GetTypeString< T >::name() << ", size: 0";
}

template< typename T >
Array< T >::Array( unsigned int n ) : _arr( new T[ n ] ), _size( n ) {
	LOGC( DEBUG ) << "Array constructor called for type " << GetTypeString< T >::name() << ", size: " << n;

	if ( !is_pointer< T >::value )
		return ;

	for ( size_t i = 0; i < n; i++ ) {
		this->_arr[ i ] = 0;
	}
}

template< typename T >
Array< T >::Array( const Array &other ) : _arr( new T[ other._size ] ), _size( other._size ) {
	LOGC( DEBUG ) << "Array copy constructor called for type " << GetTypeString< T >::name() << ", size: " << this->_size;
	for ( size_t i = 0; i < other._size; i++ ) {
		this->_arr[ i ] = other._arr[ i ];
	}
}

template< typename T >
Array< T >::~Array( void ) {
	LOGC( DEBUG ) << "Array destructor called for type " << GetTypeString< T >::name() << ", size: " << this->_size;

	if ( this->_arr )
		delete[] this->_arr;
}

template< typename T >
Array< T >	&Array< T >::operator=( const Array &other ) {
	LOGC( DEBUG ) << "Array assignation called for type " << GetTypeString< T >::name() << ", size: " << other._size;
	if ( this == &other )
		return  ( *this );

	delete[] this->_arr;

	this->_size = other._size;
	this->_arr = new T[ other._size ];

	for ( size_t i = 0; i < other._size; i++ ) {
		this->_arr[ i ] = other._arr[ i ];
	}
	return ( *this );
}

template< typename T >
std::ostream	&operator<<( std::ostream &os, const Array< T > &add ) {
	os << &add;
	return ( os );
}

template< typename T >
T	&Array< T >::operator[]( size_t n ) {
	if ( n >= this->_size )
		throw ( std::out_of_range( "Index is out of range." ) );

	return ( this->_arr[ n ] );
}

template< typename T >
size_t	Array< T >::size( void ) const {
	return ( this->_size );
}

template< typename T >
void	Array< T >::display( void ) const {
	std::stringstream	ss;

	for ( size_t i = 0; i < this->_size; i++ ) {
		ss << this->_arr[ i ];

		if ( i < this->_size - 1 )
			ss << ", ";
	}
	LOGC( INFO ) << "Display array: " << ss.str();
}
