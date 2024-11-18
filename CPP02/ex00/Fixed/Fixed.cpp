/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/18 06:08:18 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedValue(0) {
	log(2, std::cout, "Default constructor called");
}

Fixed::Fixed( const Fixed &other ) {
	log(2, std::cout, "Copy constructor called");
	*this = other;
}

Fixed::~Fixed( void ) {
	log(1, std::cout, "Destructor called");
}

Fixed&	Fixed::operator=( const Fixed &other ) {
	log(3, std::cout, "Copy assignement operator called");
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	log(0, std::cout, "GetRawBits member function called");
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw ) {
	log(0, std::cout, "SetRawBits member function called");
	this->_fixedValue = raw;
}
