/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:38:21 by Théo              #+#    #+#             */
/*   Updated: 2024/10/22 06:20:34 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class HarlFilter {

	public:
		HarlFilter( void );
		~HarlFilter( void );
		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	_display_complain( int level );

};

#endif
