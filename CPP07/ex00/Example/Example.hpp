/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:22:23 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/20 10:09:17 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Example {
	private:
		std::string	_name;

	public:
		Example( void );
		Example( const std::string name );
		~Example( void );
		Example	&operator=( const Example &other );

		const std::string	&GetName( void ) const;
};

std::ostream	&operator<<( std::ostream &os, const Example &add );
