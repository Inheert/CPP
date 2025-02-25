/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:26:56 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 09:32:05 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {
	LOGC( GREEN ) << "Cat default constructor.";
}

Cat::~Cat( void ) {
	LOGC( RED ) << "Cat destructor.";
}

Cat::Cat( const Cat &other ) : Animal( other ) {
	LOGC( GREEN ) << "Cat copy constructor.";
}

Cat	&Cat::operator=( const Cat &other ) {
	Animal::operator=( other );

	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	return ( *this );
}

void	Cat::makeSound( void ) const {
	LOG() << "Miaou";
}
