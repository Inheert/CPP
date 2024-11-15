/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:29 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/14 06:31:12 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap/ClapTrap.hpp"
#include <iostream>

int	main( void ) {
	ClapTrap a = ClapTrap("aClap");
	ClapTrap b = ClapTrap();

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	a.attack(b.getName());
	return (0);
}
