/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:20 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 05:04:38 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"

class Animal {
	protected:
		std::string	_type;

	public:
		Animal( void );
		virtual ~Animal( void );

		Animal( const std::string type );
		Animal( const Animal &other );

		Animal	&operator=( const Animal &other );

		void	setType( const std::string newType );
		std::string	getType( void ) const;

		virtual void	makeSound( void ) const;
};
