/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:27:20 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 08:18:33 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"

class Brain
{
	private:
		std::string	_ideas[ 100 ];

	public:
		Brain( void );
		~Brain( void );

		Brain( Brain const &other );
		Brain&	operator=( Brain const &other );

		std::string const*	getIdeas( void ) const;
		void	setIdeas( std::string idea, unsigned int idx );
};
