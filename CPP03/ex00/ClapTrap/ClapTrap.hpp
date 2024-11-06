/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:27 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/06 10:30:16 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_damage;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &other );
		~ClapTrap( void );

		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
		void		cantDoAnyAction( std::string action ) const;

		std::string		getName( void ) const;
		unsigned int	getHealth( void ) const;
		unsigned int	getDamage( void ) const;

		ClapTrap &operator=( const ClapTrap &other );
};
