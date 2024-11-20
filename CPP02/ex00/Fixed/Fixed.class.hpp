/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:07 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/20 08:27:21 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#ifdef _WIN32
	#define LEND "\r\n"
#else
	#define LEND "\n"
#endif

void	log(std::ostream &os, const std::string &message, ...);

class	Fixed {

	public:
		Fixed( void );
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixedValue;
		static const int	_fractionalBits;
};
