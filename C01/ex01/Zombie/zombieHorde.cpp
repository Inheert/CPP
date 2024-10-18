/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:38:47 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:56:22 by Théo             ###   ########.fr       */
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