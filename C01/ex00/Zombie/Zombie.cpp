/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:58:27 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:48:56 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	this->_name = name;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " have been destroyed.\n";
}

void	Zombie::Annouce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << "\n";
}