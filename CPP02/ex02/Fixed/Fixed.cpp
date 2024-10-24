/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/23 09:08:37 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedValue(0) {}

Fixed::Fixed( const Fixed &other ) {
	*this = other;
}

Fixed::Fixed( const int value ) : _fixedValue(value << _fractionalBits) {}

Fixed::Fixed( const float value ) : _fixedValue(roundf(value * (1 << _fractionalBits))) {}

Fixed::~Fixed( void ) {}

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

Fixed	&Fixed::operator=( const Fixed &other ) {
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return (*this);
}

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

Fixed	&Fixed::operator++( void ) {
	this->_fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	old = *this;
	this->operator++();
	return (old);
}

Fixed	&Fixed::operator--( void ) {
	this->_fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed old = *this;
	this->operator--();
	return (old);
}

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed ) {
	os << fixed.toFloat();
	return (os);
}

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
