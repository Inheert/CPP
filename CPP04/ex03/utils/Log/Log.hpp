/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:39 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/26 13:32:49 by tclaereb         ###   ########.fr       */
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
#define MSG() Log( true )
#define MSGC( color ) Log( color, true )

// Macro used to customize the Log header.
#define LOGFLAGS( flags ) { Log::logData = flags; }

// These are flags used to define what we want to see in the header.
#define FL_FILE Log::logFile
#define FL_FUNC Log::logFunc
#define FL_LINE Log::logLine

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
		std::string			_file;
		std::string			_func;
		std::string			_line;

		bool				_msg;

	public:
		static int const	logFile;
		static int const	logFunc;
		static int const	logLine;

		static int			logData;

		Log( std::string file, std::string func, int line );
		Log( enumColors color, std::string file, std::string func, int line );
		Log( bool msg );
		Log( enumColors color, bool msg );

		~Log();

		void	displayDebug( enumColors color );

		template <typename T>
		Log &operator<<( T const &msg ) {
			os << msg;
			return (*this);
		}
};
