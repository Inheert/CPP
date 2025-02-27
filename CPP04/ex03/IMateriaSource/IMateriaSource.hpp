/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:20:57 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 06:20:44 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"
#include "../AMateria/AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource( void ) {};
		virtual void learnMateria( AMateria* m ) = 0;
		virtual AMateria* createMateria( std::string const & type ) = 0;
};
