/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:29 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 04:32:54 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap/DiamondTrap.hpp"
#include <iostream>

int	main( void ) {
	DiamondTrap b;
	DiamondTrap a("weo");
	std::cout << a.getHealth() << "  " << a.getEnergy() << "  " << a.getDamage() << std::endl;
	//a.highFivesGuys();
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.attack(a.getName());
	a.takeDamage(b.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b = DiamondTrap("NewOne");
	std::cout << b.getHealth() << "  " << b.getEnergy() << "  " << b.getDamage() << std::endl;
	b.whoAmI();
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
