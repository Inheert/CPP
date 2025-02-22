/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:39 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/22 15:49:38 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#ifdef _WIN32
	#define LEND "\r\n"
#else
	#define LEND "\n"
#endif

// Macro used to call Log() constructor without having to specify the macro used by the Log class.
#define LOG() Log( __FILE__, __PRETTY_FUNCTION__, __LINE__ )
#define LOGC( color ) Log( color, __FILE__, __PRETTY_FUNCTION__, __LINE__ )

// Macro used to customize the Log header.
#define HEADERWIDTH( width ) { Log::header_len = width; }
#define ENABLEHEADER( boolean ) { Log::header_enable = boolean; }
#define HEADERFLAGS( flags ) { Log::header_perm = flags; }

// These are flags used to define what we want to see in the header.
#define FL_FILE Log::permFile
#define FL_FUNC Log::permFunc
#define FL_LINE Log::permLine

// Friendly color call.
enum	enumColors {
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	DEFAULT,
};

class Log {
	private:
		static std::ostream	&os;
		bool				first;
		std::string			file;
		std::string			func;
		int					line;

	public:
		static int const	permFile;
		static int const	permFunc;
		static int const	permLine;

		static int			header_len;
		static bool			header_enable;
		static int			header_perm;

		Log( std::string file, std::string func, int line );
		Log( enumColors color, std::string file, std::string func, int line );

		~Log();

		void	displayDebug( enumColors color );
		void	writeCentered( std::ostream &os, const std::string &text, int width );

		template <typename T>
		Log &operator<<( T const &msg ) {
			os << msg;
			return (*this);
		}
};
