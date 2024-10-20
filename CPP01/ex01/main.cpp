/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:00:04 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 12:00:22 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(int argc, char **argv) {
	Zombie	*horde;
	int		N = 5;

	if (argc > 1 && atoi(argv[1]) > 0)
		N = atoi(argv[1]);
	if (argc > 2)
		horde = zombieHorde(N, argv[2]);
	else
		horde = zombieHorde(N, "Didier");

	for (int i = 0; i < N; i++) {
		horde[i].Annouce();
	}

	delete []horde;
	return (0);
}
