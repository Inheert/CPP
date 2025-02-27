/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:01:00 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 13:45:46 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"
#include "../ICharacter/ICharacter.hpp"
#include "../AMateria/AMateria.hpp"

class Character : public virtual ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[ 4 ];

		void	copyData( Character const & other );

	public:
		Character( void );
		~Character( void );

		Character( std::string const name );
		Character( Character const & other );
		Character& operator=( Character const & other );

		AMateria ** getInventory( void ) const;

		// Inherited method
		std::string const & getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
};
