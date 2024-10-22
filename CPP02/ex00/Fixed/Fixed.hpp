/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:07 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/22 08:25:34 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>

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

#endif
