/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:20 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 14:20:43 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "../utils/Log/Log.hpp"
#include "../Brain/Brain.hpp"

class AAnimal {
	protected:
		std::string	_type;

		AAnimal( void );
		AAnimal( const std::string type );
		AAnimal( const AAnimal &other );

		AAnimal	&operator=( const AAnimal &other );

	public:
		virtual ~AAnimal( void );


		void	setType( const std::string newType );
		std::string	getType( void ) const;

		virtual void	makeSound( void ) const = 0;
		virtual	Brain*	getBrain( void ) const = 0;
};
