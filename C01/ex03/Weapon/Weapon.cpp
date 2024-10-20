/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:13 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 15:13:18 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ) : _type(weapon) {}

Weapon::~Weapon( void ) {
	std::cout << "Weapon: " << this->_type << " have been destroyed.\n";
}

void	Weapon::setType( std::string type ) {
	this->_type = type;
}

const std::string	&Weapon::getType( void ) {
	const std::string &typeREF = this->_type;
	return (typeREF);
}




