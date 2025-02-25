/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:58:27 by Théo              #+#    #+#             */
/*   Updated: 2025/02/19 10:25:12 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("zombie") {}

Zombie::Zombie( std::string name ) : _name(name) {}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " have been destroyed." << std::endl;
}

void	Zombie::Annouce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << "" << std::endl;
}

void	Zombie::SetName( std::string name ) {
	this->_name = name;
}
