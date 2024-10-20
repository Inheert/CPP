/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:38:21 by Théo              #+#    #+#             */
/*   Updated: 2024/10/20 14:52:05 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {

	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level );		

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

};

#endif