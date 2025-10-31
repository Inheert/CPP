/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:51:08 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/31 09:20:58 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include "../includes/proto.hpp"

template< typename T >
int	easyfind( const T& container, const int n ) {
	typename T::const_iterator iter = std::find( container.begin(), container.end(), n );

	if ( iter == container.end() )
		return ( -1 );

	return ( std::distance( container.begin(), iter ) );
}
