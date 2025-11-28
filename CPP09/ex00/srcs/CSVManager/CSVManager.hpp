/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSVManager.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:21:51 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/27 16:01:00 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>


class CSVManager {
	private:
		CSVManager( void );
		std::map< std::string, int >	data;

	public:
		CSVManager( const std::string &filename, const char sep );
		CSVManager( const CSVManager &other );
		CSVManager	&operator=( const CSVManager &other );
		~CSVManager( void );

		std::map< std::string, int >	getData( void );


};
