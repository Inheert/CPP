/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:58:25 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:45:43 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "Zombie.h"

class	Zombie {
	public:
		Zombie( std::string name );
		~Zombie( void );

		void	Annouce( void );
	private:
		std::string	_name;
};

#endif