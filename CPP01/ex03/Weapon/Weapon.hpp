/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:15 by Théo              #+#    #+#             */
/*   Updated: 2024/11/15 06:39:47 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Weapon {
	private:
		std::string	_type;

	public:
		Weapon( std::string weapon );
		~Weapon( void );

		void				setType( std::string type );
		const std::string	&getType( void ) const;
};
