/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/22 12:47:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed( const int value ) : _fixedValue(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) : _fixedValue(roundf(value * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
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

Fixed&	Fixed::operator=( const Fixed &other ) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed ) {
	os << fixed.toFloat();
	return (os);
}

