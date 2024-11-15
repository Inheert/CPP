/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:28:10 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/15 10:50:48 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap() {
	ClapTrap::_name = "defaultName_clap_name";
	this->_name = "defaultName";

	this->_className = "DiamondTrap";
	this->_health = FragTrap::_healthConst;
	this->_damage = FragTrap::_damageConst;
	this->_energy = ScavTrap::_energyConst;

	std::cout << GREEN << this->_className << " default constructor called." << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name") {
	this->_name = name;

	this->_className = "DiamondTrap";
	this->_health = FragTrap::_healthConst;
	this->_damage = FragTrap::_damageConst;
	this->_energy = ScavTrap::_energyConst;

	std::cout << GREEN <<  this->_className << " constructor called: " << name << "." << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;

	std::cout << GREEN << this->_className << " copy constructor called." << DEFAULT << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << RED << "DiamondTrap destructor called: " << this->_name << "." << DEFAULT << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &other ) {
	if (this == &other)
		return (*this);

	FragTrap::operator=(other);
	ScavTrap::operator=(other);

	std::cout << YELLOW << this->_className << " operator = called." << DEFAULT << std::endl;
	return (*this);
}
