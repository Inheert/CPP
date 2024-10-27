/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:00:04 by Théo              #+#    #+#             */
/*   Updated: 2024/10/27 08:21:59 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	Zombie	zombie("Carlos");
	randomChump("David");
	Zombie	*zombie2 = new Zombie("Franklin");
	Zombie	*zombie3 = newZombie("Gerald");
	delete zombie2;
	delete zombie3;
}
