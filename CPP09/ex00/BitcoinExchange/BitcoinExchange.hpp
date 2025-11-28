/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:29:49 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/28 14:31:45 by tclaereb         ###   ########.fr       */
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
#include "../utils/Log/Log.hpp"

class BitcoinExchange {
	private:
		std::map< std::string, int > data;

	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &other );
		BitcoinExchange	&operator=( const BitcoinExchange &other );
		~BitcoinExchange( void );


};
