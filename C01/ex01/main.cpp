/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:00:04 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:57:09 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "Didier");
	
	for (int i = 0; i < N; i++) {
		horde[i].Annouce();
	}
	delete []horde;
	return (0);
}
