/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:06 by Théo              #+#    #+#             */
/*   Updated: 2024/10/27 08:27:24 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../Weapon/Weapon.hpp"


class HumanA {

	public:
		HumanA( std:: string name, Weapon &weapon );
		~HumanA( void );
		void	attack( void );

	private:
		std::string	_name;
		Weapon		&_weapon;

};
