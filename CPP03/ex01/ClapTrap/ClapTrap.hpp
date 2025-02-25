/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:27 by tclaereb          #+#    #+#             */
/*   Updated: 2025/01/27 09:21:25 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define DEFAULT "\033[0m"
#define RED "\033[1;41m"
#define GREEN "\033[1;42m"
#define YELLOW "\033[1;43m"

class ClapTrap
{
	protected:
		std::string		_className;
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_damage;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &other );
		virtual	~ClapTrap( void );

		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
		void		cantDoAnyAction( std::string action ) const;

		std::string		getName( void ) const;
		unsigned int	getHealth( void ) const;
		unsigned int	getDamage( void ) const;
		unsigned int	getEnergy( void ) const;

		ClapTrap &operator=( const ClapTrap &other );
};
