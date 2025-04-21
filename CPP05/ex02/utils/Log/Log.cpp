/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:35 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/18 07:48:51 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

int const		Log::logFile = 1;
int const		Log::logFunc = 2;
int const		Log::logLine = 4;

std::ostream	&Log::os = std::cout;
int				Log::logData = FL_NONE;

std::string const	colors[] = {
	"\033[0;31m",
	"\033[0;32m",
	"\033[0;33m",
	"\033[0;34m",
	"\033[0;35m",
	"\033[0;36m",
	"\033[0;37m",
	"\033[0m",
};

Log::Log( std::string file, std::string func, int line ) {
	std::stringstream	ss;

	ss << line;
	this->_file = logData & logFile ? "./" + file : "";
	this->_func = logData & logFunc ? func : "";
	this->_line = logData & logLine ? ss.str() : "";

	this->displayDebug( DEFAULT );
}

Log::Log( enumColors color, std::string file, std::string func, int line ) {
	std::stringstream	ss;

	ss << line;

	this->_file = logData & logFile ? "./" + file : "";
	this->_func = logData & logFunc ? func : "";
	this->_line = logData & logLine ? ss.str() : "";

	this->displayDebug( color );
}

Log::~Log() {
	if ( ( logData & logFile ) && ( logData & logLine ) && ( logData & logFunc ) )
		os << " - \033[3m(" << this->_file << ":" << this->_line << " " << this->_func << ")\033[0m";
	else if ( ( logData & logFile ) && ( logData & logLine ) )
		os << " - \033[3m(" << this->_file << ":" << this->_line << ")\033[0m";
	else if ( ( logData & logFile ) && ( logData & logFunc ) )
		os << " - \033[3m(" << this->_file << " " << this->_func << ")\033[0m";
	else if ( ( logData & logLine ) && ( logData & logFunc ) )
		os << " - \033[3m(" << this->_line << " " << this->_func << ")\033[0m";
	else if ( logData & logFile )
		os << " - \033[3m(" << this->_file << ")\033[0m";
	else if ( logData & logLine )
		os << " - \033[3m(" << this->_line << ")\033[0m";
	else if ( logData & logFunc )
		os << " - \033[3m(" << this->_func << ")\033[0m";

	os << LEND;

	os << colors[ DEFAULT ];
}

void	Log::displayDebug( enumColors color ) {
	os << colors[color] << "[LOG] - ";
}
