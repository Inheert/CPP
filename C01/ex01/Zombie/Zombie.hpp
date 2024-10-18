/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:58:25 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 00:51:32 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "Zombie.h"

class	Zombie {
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void	Annouce( void );
		void	SetName( std::string );
	private:
		std::string	_name;
};


#endif