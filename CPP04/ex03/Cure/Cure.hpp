/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:18:06 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 13:49:25 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/Log/Log.hpp"
#include "../AMateria/AMateria.hpp"

class AMateria;

class Cure : public virtual AMateria
{
	public:
		Cure( void );
		~Cure( void );

		Cure( Cure const & other );
		Cure& operator=( Cure const & other );

		// Inherited method
		AMateria* clone( void ) const;
		void use( ICharacter& target );
};
