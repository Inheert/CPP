/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:15 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 14:59:25 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon {
	
	public:
		Weapon( std::string weapon );
		~Weapon( void );
		
		void				setType( std::string type );
		const std::string	&getType( void );

	private:
		std::string	_type;

};

#endif
