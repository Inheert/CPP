/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:46:38 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/15 10:51:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ClapTrap/ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		bool	_is_guarding_gate;

		const static int	_healthConst;
		const static int	_damageConst;
		const static int	_energyConst;

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &other );
		virtual	~ScavTrap( void );

		ScavTrap &operator=( const ScavTrap &other );

		bool	getGuardingMode();

		void	attack( const std::string &target );
		void	guardGate( void );
};
