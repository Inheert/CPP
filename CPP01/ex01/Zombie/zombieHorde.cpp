/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:38:47 by Théo              #+#    #+#             */
/*   Updated: 2025/02/19 10:23:28 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie	*zombieHorde( int N, std::string name ) {
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].SetName(name);
	}
	return (horde);
}
