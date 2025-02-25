/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:20 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 09:35:40 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "../utils/Log/Log.hpp"
#include "../Brain/Brain.hpp"

class A_Animal {
	protected:
		std::string	_type;

		A_Animal( void );
		A_Animal( const std::string type );
		A_Animal( const A_Animal &other );

		A_Animal	&operator=( const A_Animal &other );

	public:
		virtual ~A_Animal( void );


		void	setType( const std::string newType );
		std::string	getType( void ) const;

		virtual void	makeSound( void ) const = 0;
		virtual	Brain*	getBrain( void ) const = 0;
};
