/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:25:53 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/27 13:20:41 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/proto.hpp"

class Span {
	private:
		std::set< int >	_container;
		unsigned int	_size;

	public:
		Span( void );
		Span( const unsigned int n );
		Span( const Span& other );
		~Span( void )

		Span&	operator=( const Span& other );

		void	addNumber( const unsigned int n );

		unsigned int	shortestSpan( void ) const;
		unsigned int	highestSpan( void ) const;
};
