/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:35 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/28 10:25:44 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

int const		Log::logFile = 1;
int const		Log::logFunc = 2;
int const		Log::logLine = 4;

// std::ostream	&Log::os = std::cout;
int				Log::logData = FL_NONE;
bool			Log::debug = true;

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
	this->_color = DEFAULT;
	std::stringstream	ss;

	ss << line;
	this->_file = logData & logFile ? "./" + file : "";
	this->_func = logData & logFunc ? func : "";
	this->_line = logData & logLine ? ss.str() : "";

	this->displayDebug( DEFAULT );
}

Log::Log( enumColors color, std::string file, std::string func, int line ) {
	this->_color = color;
	if ( !debug && color == DEBUG )
		return ;

	std::stringstream	ss;
	ss << line;

	this->_file = logData & logFile ? "./" + file : "";
	this->_func = logData & logFunc ? func : "";
	this->_line = logData & logLine ? ss.str() : "";

	this->displayDebug( color );
}

Log::Log( const Log& other ) {
	this->os.str( other.os.str() );
	this->_file = other._file;
	this->_func = other._func;
	this->_line = other._line;
	this->_color = other._color;
}

Log&	Log::operator=( const Log& other ) {
	if ( this == &other )
		return ( *this );

	this->os.str( other.os.str() );
	this->_file = other._file;
	this->_func = other._func;
	this->_line = other._line;
	this->_color = other._color;
	return ( *this );
}

Log::~Log() {
	if ( !debug && this->_color == DEBUG ) {
		return ;
	}

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

	std::cout << os.str();
}

void	Log::displayDebug( enumColors color ) {
	os << colors[color] << "[LOG] - ";
}
