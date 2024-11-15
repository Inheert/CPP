/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:13 by Théo              #+#    #+#             */
/*   Updated: 2024/11/15 06:39:11 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ) : _type(weapon) {}

Weapon::~Weapon( void ) {}

void	Weapon::setType( std::string type ) {
	this->_type = type;
}

const std::string	&Weapon::getType( void ) const {
	const std::string &typeREF = this->_type;
	return (typeREF);
}
