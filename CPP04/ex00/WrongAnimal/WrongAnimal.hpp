/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:47:12 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 15:23:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		virtual ~WrongAnimal( void );

		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal const &other );
		WrongAnimal	&operator=( WrongAnimal const &other );

		std::string		getType( void ) const;
		void	makeSound( void ) const;
};
