/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:35 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/22 15:56:47 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"

int const		Log::permFile = 1;
int const		Log::permFunc = 2;
int const		Log::permLine = 4;

std::ostream	&Log::os = std::cout;
int				Log::header_perm = Log::permFile | Log::permFunc | Log::permLine;
int				Log::header_len = 50;
bool			Log::header_enable = false;


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

Log::Log( std::string file, std::string func, int line )
			: first( true ), file( "./" + file ), func( func ), line( line ) {
	this->displayDebug( DEFAULT );
}

Log::Log( enumColors color, std::string file, std::string func, int line )
			: first( true ), file( "./" + file ), func( func ), line( line ) {
	this->displayDebug( color );
}

Log::~Log() {
	for ( int i = 0; i < header_len && header_enable; i++ )
		os << "░";
	os << LEND;
	os << colors[DEFAULT];
}

void	Log::writeCentered( std::ostream &os, const std::string &text, int width ) {
	int	padding = (width - text.length()) / 2;

	for (int i = 0; i < padding; i++)
		os << " ";

	os << text;

	for (int i = 0; i < padding; i++)
		os << " ";

	os << LEND;
}

void	Log::displayDebug( enumColors color ) {
	os << colors[color];

	if (this->first && header_enable) {

		os << "\033[1m" << "⌜" << std::setw(header_len) << "" << "⌝" << LEND;

		if ( header_perm & permFile )
			this->writeCentered(os, this->file, header_len);
		if ( header_perm & permFunc )
			this->writeCentered(os, this->func, header_len);

		if ( header_perm & permLine ) {
			std::ostringstream cast;
			cast << this->line;
			this->writeCentered(os, "Line: " + cast.str(), header_len);
		}

		os << "⌞" << std::setw(header_len) << "" << "⌟" << colors[color] << LEND;

		for (int i = 0; i < header_len; i++)
			os << "░";
		os << LEND;

		this->first = false;
	}
}
