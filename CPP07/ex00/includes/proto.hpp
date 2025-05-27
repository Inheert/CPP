/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:40:19 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/22 09:32:45 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/Log/Log.hpp"
#include "../Example/Example.hpp"

template< typename T >
void	swap( T &lhs, T &rhs ) {
	T	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template< typename T >
T	min( T lhs, T rhs ) {
	if ( lhs < rhs )
		return ( lhs );
	return ( rhs );
}

template< typename T >
T max( T lhs, T rhs ) {
	if ( lhs > rhs )
		return ( lhs );
	return ( rhs );
}

