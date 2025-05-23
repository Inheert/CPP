/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:19:42 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 13:51:30 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"
#include "../Character/Character.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria( void );
		virtual ~AMateria( void );

		AMateria( AMateria const & other );
		AMateria( std::string const & type );
		AMateria& operator=( AMateria const & other );

		std::string const & getType( void ) const;

		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target );
};
