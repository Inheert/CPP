/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:29 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 04:05:53 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap/FragTrap.hpp"
#include <iostream>

int	main( void ) {
	FragTrap b;
	FragTrap a("aTrap");
	a.highFivesGuys();
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b = FragTrap("NewOne");
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
