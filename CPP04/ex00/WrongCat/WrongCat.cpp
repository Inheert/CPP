/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:31 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 15:25:15 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "Cat" ) {
	LOGC( GREEN ) << "WrongCat default constructor.";
}

WrongCat::~WrongCat( void ) {
	LOGC( RED ) << "WrongCat destructor.";
}

WrongCat::WrongCat( WrongCat const &other ) : WrongAnimal( other.getType() ) {
	LOGC( GREEN ) << "WrongCat copy constructor.";
}

WrongCat&	WrongCat::operator=( WrongCat const &other ) {
	WrongAnimal::operator=( other );

	LOGC( YELLOW ) << "WrongCat assignation overload.";

	return ( *this );
}
