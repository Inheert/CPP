/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:38:38 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/24 08:18:52 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Fixed/Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point( void );
		Point( const float x, const float y );
		Point( const Point &other );
		~Point( void );

		const Fixed	&getX( void ) const;
		const Fixed &getY( void ) const;

		Point	&operator=( const Point &other );
		Fixed	operator-( const Point &other ) const;
};
