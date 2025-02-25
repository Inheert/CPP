/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:26:53 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 09:32:09 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {
	LOGC( GREEN ) << "Dog default constructor.";
}

Dog::~Dog( void ) {
	LOGC( RED ) << "Dog destructor.";
}

Dog::Dog( const Dog &other ) : Animal( other ) {
	LOGC( GREEN ) << "Dog copy constructor.";
}

Dog	&Dog::operator=( const Dog &other ) {
	Animal::operator=( other );

	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	return ( *this );
}

void	Dog::makeSound() const {
	LOG() << "Woof!";
}
