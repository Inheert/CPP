/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:08 by Théo              #+#    #+#             */
/*   Updated: 2024/10/21 12:14:31 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {}

HumanB::~HumanB( void ) {
	//std::cout << "HumanB: " << this->_name << " have been destroyed." << std::endl;
}

void	HumanB::attack( void ) {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "" << std::endl;
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon	= &weapon;
}
