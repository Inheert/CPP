/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:21:58 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/14 09:25:31 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->_className = "ScavTrap";
	this->_health = 100;
	this->_damage = 20;
	this->_energy = 50;
	this->_is_guarding_gate = false;

	std::cout << GREEN << this->_className << " default constructor called." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->_className = "ScavTrap";
	this->_health = 100;
	this->_damage = 20;
	this->_energy = 50;
	this->_is_guarding_gate = false;

	std::cout << GREEN << this->_className << " default constructor called." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	*this = other;

	std::cout << GREEN << this->_className << " copy constructor called: " << this->_name << "." << DEFAULT << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << RED << "ScavTrap destructor called: " << this->_name << "." << DEFAULT << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &other ) {
	if (this == &other)
		return (*this);

	ClapTrap::operator=(other);

	std::cout << YELLOW << this->_className << " operator = called." << DEFAULT << std::endl;
	return (*this);
}

bool	ScavTrap::getGuardingMode( void ) {
	return (this->_is_guarding_gate);
}

void	ScavTrap::attack(  const std::string &target ) {
		if (!this->_energy || !this->_health)
		return (this->cantDoAnyAction("attack"));

	this->_energy--;

	std::cout << this->_className << this->_name << " smashed " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	this->_is_guarding_gate = !this->_is_guarding_gate;

	if (this->_is_guarding_gate)
		std::cout << this->_className << " is now in gate keeper mode." << std::endl;
	else
		std::cout << this->_className << " is no longer in gate keeper mode." << std::endl;
}
