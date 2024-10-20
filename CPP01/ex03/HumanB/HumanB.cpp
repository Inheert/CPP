/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:08 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 15:42:17 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {}

HumanB::~HumanB( void ) {
	//std::cout << "HumanB: " << this->_name << " have been destroyed.\n";
}

void	HumanB::attack( void ) {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "\n";
	else
		std::cout << this->_name << " has no weapon!\n";
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon	= &weapon;
}
