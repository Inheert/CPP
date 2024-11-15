/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:06 by Théo              #+#    #+#             */
/*   Updated: 2024/11/15 06:39:55 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../Weapon/Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA( std:: string name, Weapon &weapon );
		~HumanA( void );
		void	attack( void );
};
