/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/20 08:46:35 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

inline void log(std::ostream &os, const std::string &message, ...) {
	os << "[LOG] - " << message << LEND;
}

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedValue(0) {
	log(std::cout, "Default constructor called", 2, NULL);
}

Fixed::Fixed( const Fixed &other ) {
	log(std::cout, "Copy constructor called", 2, NULL);
	*this = other;
}

Fixed::~Fixed( void ) {
	log(std::cout, "Destructor called", 1, NULL);
}

Fixed&	Fixed::operator=( const Fixed &other ) {
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	log(std::cout, "Copy assignement operator called", 3, NULL);
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	log(std::cout, "GetRawBits member function called", NULL);
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw ) {
	log(std::cout, "SetRawBits member function called", NULL);
	this->_fixedValue = raw;
}
