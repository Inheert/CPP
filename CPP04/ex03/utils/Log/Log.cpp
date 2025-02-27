/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:35 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 13:32:13 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

int const		Log::logFile = 1;
int const		Log::logFunc = 2;
int const		Log::logLine = 4;

std::ostream	&Log::os = std::cout;
int				Log::logData = Log::logFile | Log::logFunc | Log::logLine;

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
	this->_msg = false;

	this->displayDebug( DEFAULT );
}

Log::Log( enumColors color, std::string file, std::string func, int line ) {
	std::stringstream	ss;

	ss << line;

	this->_file = logData & logFile ? "./" + file : "";
	this->_func = logData & logFunc ? func : "";
	this->_line = logData & logLine ? ss.str() : "";
	this->_msg = false;

	this->displayDebug( color );
}

Log::Log( bool msg ) {
	(void)msg;

	this->_file = "";
	this->_func = "";
	this->_line = "";
	this->_msg = true;

	this->displayDebug( DEFAULT );
}

Log::Log( enumColors color, bool msg ) {
	(void)msg;

	this->_file = "";
	this->_func = "";
	this->_line = "";
	this->_msg = true;

	this->displayDebug( color );
}


Log::~Log() {
	if ( ( logData & logFile ) && ( logData & logLine ) && ( logData & logFunc ) && !this->_file.empty() && !this->_func.empty() && !this->_line.empty() )
		os << " - \033[3m(" << this->_file << ":" << this->_line << " " << this->_func << ")\033[0m";
	else if ( ( logData & logFile ) && ( logData & logLine ) && !this->_file.empty() && !this->_line.empty() )
		os << " - \033[3m(" << this->_file << ":" << this->_line << ")\033[0m";
	else if ( ( logData & logFile ) && ( logData & logFunc ) && !this->_file.empty() && !this->_func.empty() )
		os << " - \033[3m(" << this->_file << " " << this->_func << ")\033[0m";
	else if ( ( logData & logLine ) && ( logData & logFunc ) && !this->_line.empty() && !this->_func.empty() )
		os << " - \033[3m(" << this->_line << " " << this->_func << ")\033[0m";
	else if ( ( logData & logFile ) && !this->_file.empty() )
		os << " - \033[3m(" << this->_file << ")\033[0m";
	else if ( ( logData & logLine ) && !this->_line.empty() )
		os << " - \033[3m(" << this->_line << ")\033[0m";
	else if ( ( logData & logFunc ) && !this->_func.empty() )
		os << " - \033[3m(" << this->_func << ")\033[0m";

	os << LEND;

	os << colors[ DEFAULT ];
}

void	Log::displayDebug( enumColors color ) {
	if ( !this->_msg )
		os << colors[color] << "[LOG] - ";
	else
		os << colors[color] << "[MSG] - ";
}
