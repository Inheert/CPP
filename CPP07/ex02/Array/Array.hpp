/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:29:09 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/30 10:23:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <typeinfo>
#include "../includes/proto.hpp"
#include "stdint.h"

template< typename T >
class	Array {
	private:
		T		*_arr;
		size_t	_size;

	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array &other );
		~Array( void );

		Array	&operator=( const Array &other );
		T		&operator[]( size_t n );

		size_t	size( void ) const;
		void	display( void ) const;
};

template< typename T >
std::ostream	&operator<<( std::ostream &os, const Array< T > &add );

template< typename T  > struct GetTypeString< Array< T > > { static std::string name() { return ( "Array<T>" ); } };

#include "Array.tpp"
