/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/24 10:14:13 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ATTRIBUTS

const int Fixed::_fractionalBits = 8;

// CONSTRUCTORS

Fixed::Fixed( void ) : _fixedValue(0) {}

Fixed::Fixed( const Fixed &other ) {
	*this = other;
}

Fixed::Fixed( const int value ) : _fixedValue(value << _fractionalBits) {}

Fixed::Fixed( const float value ) : _fixedValue(roundf(value * (1 << _fractionalBits))) {}

Fixed::~Fixed( void ) {}

// ATTRIBUTS GETTER / SETTER

int	Fixed::getRawBits( void ) const {
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw) {
	this->_fixedValue = raw;
}

// TYPE CONVERSION

int	Fixed::toInt( void ) const {
	return (this->_fixedValue  >> this->_fractionalBits);
}

float	Fixed::toFloat( void ) const {
	return (float(this->_fixedValue) / (1 << this->_fractionalBits));
}

// STATICS METHODS

Fixed	&Fixed::min( Fixed &lhs, Fixed &rhs ) {
	return (lhs.getRawBits() <= rhs.getRawBits() ? lhs : rhs);
}

const Fixed	&Fixed::min( const Fixed lhs, const Fixed rhs ) {
	return (lhs.getRawBits() <= rhs.getRawBits() ? lhs : rhs);
}

Fixed	&Fixed::max( Fixed &lhs, Fixed &rhs ) {
	return (lhs.getRawBits() >= rhs.getRawBits() ? lhs: rhs);
}

const Fixed	&Fixed::max( const Fixed &lhs, const Fixed &rhs ) {
	return (lhs.getRawBits() >= rhs.getRawBits() ? lhs : rhs);
}

// OPERATORS OVERLOADING - AFFECTATION

Fixed	&Fixed::operator=( const Fixed &other ) {
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return (*this);
}

// OPERATORS OVERLOADING - INSERTION

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed ) {
	os << fixed.toFloat();
	return (os);
}

// OPERATORS OVERLOADING - INCREMENTATION

Fixed	&Fixed::operator++( void ) {
	this->_fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	old = *this;
	this->operator++();
	return (old);
}

// OPERATORS OVERLOADING - DECREMENTATION

Fixed	&Fixed::operator--( void ) {
	this->_fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed old = *this;
	this->operator--();
	return (old);
}

// OPERATORS OVERLOADING - ARITHMETIC

Fixed	Fixed::operator+( const Fixed &other ) const {
	Fixed temp;
	temp.setRawBits(this->getRawBits() + other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-( const Fixed &other ) const {
	Fixed temp;
	temp.setRawBits(this->getRawBits() - other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*( const Fixed &other ) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/( const Fixed &other ) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}


// OPERATORS OVERLOADING - LOGICAL

bool	operator>( const Fixed &lhs, const Fixed &rhs ) {
	return (lhs.getRawBits() > rhs.getRawBits());
}

bool	operator<(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() < rhs.getRawBits());
}

bool	operator>=(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() >= rhs.getRawBits());
}

bool	operator<=( const Fixed &lhs, const Fixed &rhs ) {
	return (lhs.getRawBits() <= rhs.getRawBits());
}

bool	operator!=( const Fixed &lhs, const Fixed &rhs ) {
	return (lhs.getRawBits() != rhs.getRawBits());
}

bool	operator==( const Fixed &lhs, const Fixed &rhs ) {
	return (lhs.getRawBits() == rhs.getRawBits());
}

