/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/20 09:40:27 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

inline void log(std::ostream &os, const std::string &message, ...) {
	os << "[LOG] - " << message << LEND;
}

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedValue(0) {
	log(std::cout, "Default constructor called", 2, NULL);
}

Fixed::Fixed( const int value ) : _fixedValue(value << _fractionalBits) {
	log(std::cout, "Int constructor called", 2, NULL);
}

Fixed::Fixed( const float value ) : _fixedValue(roundf(value * (1 << _fractionalBits))) {
	log(std::cout, "Float constructor called", 2, NULL);
}

Fixed::Fixed( const Fixed &other ) {
	log(std::cout, "Copy constructor called", 2, NULL);
	*this = other;
}

Fixed::~Fixed( void ) {
	log(std::cout, "Destructor called", 2, NULL);
}

Fixed&	Fixed::operator=( const Fixed &other ) {
	log(std::cout, "Copy assignement operator called", 3, NULL);
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed ) {
	os << fixed.toFloat();
	return (os);
}

int	Fixed::getRawBits( void ) const {
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw) {
	this->_fixedValue = raw;
}

int	Fixed::toInt( void ) const {
	return (this->_fixedValue  >> this->_fractionalBits);
}

float	Fixed::toFloat( void ) const {
	return float(this->_fixedValue) / (1 << this->_fractionalBits);
}


