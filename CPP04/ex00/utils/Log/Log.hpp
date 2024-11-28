/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:39 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/28 14:30:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#ifdef _WIN32
	#define LEND "\r\n"
#else
	#define LEND "\n"
#endif

#define LOG() Log(__FILE__, __PRETTY_FUNCTION__, __LINE__)
#define LOGC(color) Log(color, __FILE__, __PRETTY_FUNCTION__, __LINE__)

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
		static int			header_len;

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
