/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:21:19 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:24:07 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

Zombie	*newZombie( std::string name ) {
	Zombie *zombie = new Zombie(name);
	return (zombie);
}
