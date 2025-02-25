/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:31 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 03:16:09 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("defaultName"), _health(10), _energy(10), _damage(0) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _health(10), _energy(10), _damage(0) {
	std::cout << "Constructor called: " << name << "." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) {
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_damage = other._damage;

	std::cout << "Copy constructor called: " << this->_name << "." << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "Destructor called: " << this->_name << "." << std::endl;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &other ) {
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_damage = other._damage;
	return (*this);
}

std::string	ClapTrap::getName( void ) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHealth( void ) const {
	return (this->_health);
}

unsigned int	ClapTrap::getDamage( void ) const {
	return (this->_damage);
}

unsigned int	ClapTrap::getEnergy( void ) const {
	return (this->_energy);
}

void	ClapTrap::cantDoAnyAction( std::string action ) const {
	if (!this->_health)
		std::cout << "ClapTrap " << this->_name << " can't " << action << " because he is died." << std::endl;
	if (!this->_energy)
		std::cout << "ClapTrap " << this->_name << " can't " << action << " because he doesn't have enough energy." << std::endl;
}

void	ClapTrap::attack( const std::string &target ) {
	if (!this->_energy || !this->_health)
		return (this->cantDoAnyAction("attack"));

	this->_energy--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (!this->_health)
		return (this->cantDoAnyAction("take damage"));

	if (int(this->_health - amount) < 0)
		this->_health = 0;
	else
		this->_health -= amount;

	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage points!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (!this->_energy || !this->_health)
		return (this->cantDoAnyAction("repair"));

	this->_health += amount;
	this->_energy--;

	std::cout << "ClapTrap " << this->_name << " recovered " << amount << " hit points!" << std::endl;
}
