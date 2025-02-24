/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:07 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/24 08:17:44 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#ifdef _WIN32
	#define LEND "\r\n"
#else
	#define LEND "\n"
#endif

void	log(std::ostream &os, const std::string &message, ...);

class	Fixed {

	public:
		Fixed( void );
		Fixed( const int value );
		Fixed( const float value);
		Fixed( const Fixed &other );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min( Fixed &lhs, Fixed &rhs );
		static const Fixed	&min( const Fixed lhs, const Fixed rhs );
		static Fixed		&max( Fixed &lhs, Fixed &rhs );
		static const Fixed	&max( const Fixed &lhs, const Fixed &rhs );

		Fixed		&operator=( const Fixed &other );
		Fixed		operator+( const Fixed &other ) const;
		Fixed		operator-( const Fixed &other ) const;
		Fixed		operator*( const Fixed &other ) const;
		Fixed		operator/( const Fixed &other ) const;
		Fixed		&operator++( void );
		Fixed		operator++( int );
		Fixed		&operator--( void );
		Fixed		operator--( int );

	private:
		int					_fixedValue;
		static const int	_fractionalBits;

};

std::ostream	&operator<<( std::ostream &o, Fixed const &fixed );
bool			operator>( const Fixed &lhs, const Fixed &rhs );
bool			operator<( const Fixed &lhs, const Fixed &rhs );
bool			operator>=( const Fixed &lhs, const Fixed &rhs );
bool			operator<=( const Fixed &lhs, const Fixed &rhs );
bool			operator==( const Fixed &lhs, const Fixed &rhs );
bool			operator!=( const Fixed &lhs, const Fixed &rhs );
