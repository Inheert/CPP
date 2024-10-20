/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:05 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 15:09:53 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA( void ) {
	//std::cout << "HumanA: " <<  this->_name << " have been destroyed.\n";
}

void	HumanA::attack( void ) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "\n";
}
