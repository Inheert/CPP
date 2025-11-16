/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:36:28 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/13 12:40:27 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "GetType.hpp"
#include "../utils/Log/Log.hpp"
#include "easyfind.hpp"

template< typename T >
void	displayContainer( const T& container ) {
	Log	log = LOGC( INFO );

	for ( typename T::const_iterator iter = container.begin(); iter != container.end(); iter++ ) {
		log << *iter << " ";
	}
}
