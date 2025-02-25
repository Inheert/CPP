/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:28:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 04:09:58 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../ClapTrap/ClapTrap.hpp"
#include "../FragTrap/FragTrap.hpp"
#include "../ScavTrap/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap &other );
		~DiamondTrap( void );

		DiamondTrap &operator=( const DiamondTrap &other );

		void	whoAmI( void );
};
