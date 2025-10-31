/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:47:11 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/31 12:09:51 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template< typename T >
class MutantStack : public std::stack< T > {
	public:
		MutantStack( void );
		MutantStack( const MutantStack &other );
		MutantStack	&operator=( const MutantStack &other );
		~MutantStack( void );

		typedef typename std::stack< T >::container_type::iterator iterator;
		iterator	begin( void );
		iterator	end( void );

		typedef typename std::stack< T >::container_type::const_iterator const_iterator;
		const_iterator	begin( void ) const;
		const_iterator	end( void ) const;

		typedef typename std::stack< T >::container_type::reverse_iterator reverse_iterator ;
		reverse_iterator	rbegin( void );
		reverse_iterator	rend( void );

		typedef typename std::stack< T >::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin( void ) const;
		const_reverse_iterator	rend( void ) const;
};

#include "MutantStack.tpp"
