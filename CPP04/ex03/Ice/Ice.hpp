/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:56:57 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 13:49:31 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/Log/Log.hpp"
#include "../AMateria/AMateria.hpp"

class Ice : public virtual AMateria
{
	public:
		Ice( void );
		~Ice( void );

		Ice( Ice const & other );
		Ice& operator=( Ice const & other );

		// Inherited method
		AMateria*	clone( void ) const;
		void use( ICharacter& target );
};
