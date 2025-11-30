/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:29:49 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/30 17:15:19 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <climits>
#include "../utils/Log/Log.hpp"

class BitcoinExchange {
	private:
		std::map< std::string, double > _data;

		std::string	_trim( const std::string &s );
		bool		_isValidDate( const std::string &date );
	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &other );
		BitcoinExchange	&operator=( const BitcoinExchange &other );
		~BitcoinExchange( void );

		void	execute( const std::string &filename );
};
