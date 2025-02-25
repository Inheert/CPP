/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:29 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 03:58:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap/ScavTrap.hpp"
#include "ClapTrap/ClapTrap.hpp"
#include <iostream>

int	main( void ) {
	ScavTrap b;
	ScavTrap a("aTrap");

	std::cout << "'a' attributs: health: " << a.getHealth() << " damage: " << a.getDamage() << " energy: " << a.getEnergy() << "." << std::endl;
	std::cout << "'b' attributs: health: " << b.getHealth() << " damage: " << b.getDamage() << " energy: " << b.getEnergy() << "." << std::endl;
	b.guardGate();
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b = ScavTrap("NewOne");
	std::cout << "'b' attributs: health: " << b.getHealth() << " damage: " << b.getDamage() << " energy: " << b.getEnergy() << "." << std::endl;
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	//ScavTrap a = ScavTrap();
	//a = b;
	//ClapTrap b = ScavTrap();
	return (0);
}
