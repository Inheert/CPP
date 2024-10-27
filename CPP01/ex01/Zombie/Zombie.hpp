/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:58:25 by Théo              #+#    #+#             */
/*   Updated: 2024/10/27 08:24:57 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

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
