/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:22:43 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/20 10:09:27 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Example.hpp"

Example::Example( void ) : _name( "defaultName" ) {}

Example::Example( const std::string name ) : _name( name ) {}

Example::~Example( void ) {}

Example	&Example::operator=( const Example &other ) {
	if ( this == &other )
		return ( *this );
	this->_name = other._name;
	return ( *this );
}

const std::string	&Example::GetName( void ) const {
	return ( this->_name );
}

std::ostream	&operator<<( std::ostream &os, const Example &add ) {
	os << add.GetName();
	return ( os );
}
