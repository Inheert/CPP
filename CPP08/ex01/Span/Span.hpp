/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:25:53 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/15 15:29:42 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <algorithm>
#include <set>
#include <limits>
#include "../utils/Log/Log.hpp"
#include "../includes/GetType.hpp"

class Span {
	private:
		std::multiset< int >	_container;
		unsigned int	_size;

	public:
		Span( void );
		Span( const unsigned int n );
		Span( const Span& other );
		~Span( void );

		Span&	operator=( const Span& other );

		void	addNumber( const int n );
		void	addNumber( std::set< int >::iterator begin, std::set< int >::iterator end );

		int	shortestSpan( void ) const;
		int	highestSpan( void ) const;

		void	display( void ) const;
};

template<>
struct GetTypeString< Span > { static std::string name() { return ( "Span" ); } };
