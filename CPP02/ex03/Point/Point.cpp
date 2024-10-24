/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:38:33 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/24 11:34:43 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const float x, const float y ) : _x( x ), _y( y ) {}

Point::Point( const Point &other ) : _x(other.getX()), _y(other.getY()) {}

Point::~Point( void ) {}

const Fixed	&Point::getX( void ) const {
	return (this->_x);
}

const Fixed	&Point::getY( void ) const {
	return (this->_y);
}

Point	&Point::operator=( const Point &other ) {
	return (void(other), *this);
};


