/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:46:38 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/15 10:47:47 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ClapTrap/ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		const static int	_healthConst;
		const static int	_damageConst;
		const static int	_energyConst;

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &other );
		virtual	~FragTrap( void );

		FragTrap &operator=( const FragTrap &other );

		void	highFivesGuys( void );
};
