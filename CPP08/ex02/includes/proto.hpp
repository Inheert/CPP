/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:36:28 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/31 14:09:06 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "GetType.hpp"
#include "../utils/Log/Log.hpp"
#include "../MutantStack/MutantStack.hpp"

template< typename T, typename Push, typename Top, typename Pop >
void	testContainer( T& container, std::string title, Push push, Top top, Pop pop ) {
	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << title;
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	push( container, 5 );
	push( container, 18 );

	LOGC( DEBUG ) << "Top value: " << top( container );
	LOGC( DEBUG ) << "Size of the container: " << container.size();
	pop( container );
	LOGC( DEBUG ) << "Size after using pop(): " << container.size();

	std::cout << "\n";

	push( container, 54 );
	push( container, 478 );
	push( container, 11 );
	push( container, 89 );

	LOGC( DEBUG ) << "Print every values using iterator: ";
	for ( typename T::iterator it = container.begin(); it != container.end(); it++ ) {
		LOGC( DEBUG ) << "Value: " << *it;
	}

	std::cout << "\n";

	LOGC( DEBUG ) << "Print every values using const iterator: ";
	for ( typename T::const_iterator it = container.begin(); it != container.end(); it++ ) {
		LOGC( DEBUG ) << "Value: " << *it;
	}

	std::cout << "\n";

	LOGC( DEBUG ) << "Print every values using reverse iterator: ";
	for ( typename T::reverse_iterator it = container.rbegin(); it != container.rend(); it++ ) {
		LOGC( DEBUG ) << "Value: " << *it;
	}

	std::cout << "\n";

	LOGC( DEBUG ) << "Print every values using reverse const iterator: ";
	for ( typename T::const_reverse_iterator it = container.rbegin(); it != container.rend(); it++ ) {
		LOGC( DEBUG ) << "Value: " << *it;
	}
}
