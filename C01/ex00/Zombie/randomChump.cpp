/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:21:35 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:49:07 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

void	randomChump( std::string name ) {
	Zombie zombie = Zombie(name);
	zombie.Annouce();
}
