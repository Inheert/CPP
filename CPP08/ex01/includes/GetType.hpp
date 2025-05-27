/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetType.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:02:31 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/27 08:19:51 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template< typename T >
struct GetTypeString {
	static std::string name() { return ( "unknown" ); }
};


template<> struct GetTypeString< char > { static std::string name() { return ( "char" ); } };
template<> struct GetTypeString< unsigned char > { static std::string name() { return ( "unsigned char" ); } };

template<> struct GetTypeString< short > { static std::string name() { return ( "short" ); } };
template<> struct GetTypeString< unsigned short > { static std::string name() { return ( "unsigned short" ); } };

template<> struct GetTypeString< int > { static std::string name() { return ( "int" ); } };
template<> struct GetTypeString< unsigned int > { static std::string name() { return ( "unsigned int" ); } };

template<> struct GetTypeString< long > { static std::string name() { return ( "long" ); } };
template<> struct GetTypeString< unsigned long > { static std::string name() { return ( "unsigned long" ); } };
template<> struct GetTypeString< long long > { static std::string name() { return ( "long long" ); } };
template<> struct GetTypeString< unsigned long long > { static std::string name() { return ( "unsigned long long" ); } };

template<> struct GetTypeString< float > { static std::string name() { return ( "float" ); } };
template<> struct GetTypeString< double > { static std::string name() { return ( "double" ); } };
template<> struct GetTypeString< long double > { static std::string name() { return ( "long double" ); } };
template<> struct GetTypeString< bool > { static std::string name() { return ( "bool" ); } };
template<> struct GetTypeString< wchar_t > { static std::string name() { return ( "wchar_t" ); } };

template< typename T >
struct GetTypeString< T* > {
	static std::string name() { return ( GetTypeString< T >::name() + "*" ); }
};

template< typename T >
std::string typeof( const T& ) {
	return ( GetTypeString< T>::name() );
}
