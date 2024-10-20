/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:06 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 15:11:08 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "../Weapon/Weapon.hpp"


class HumanA {
	
	public:
		HumanA( std:: string name, Weapon &weapon );
		~HumanA( void );
		void	attack( void );

	private:
		std::string	_name;
		Weapon		&_weapon;

};

#endif
