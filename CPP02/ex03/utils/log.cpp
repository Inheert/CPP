/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:30:33 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/20 10:34:33 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdarg>

#ifdef _WIN32
	#define LEND "\r\n"
#else
	#define LEND "\n"
#endif

#define COLORS_LEN 15

#include <cstdio>
std::string colors[COLORS_LEN] = {
	"\033[0m", // DEFAULT
	"\033[1;31m", // RED
	"\033[1;32m", // GREEN
	"\033[1;33m", // YELLOW
};

void	log(std::ostream &os, const std::string &message, ...) {
	va_list			args;
	void			*arg;
	unsigned long	value;

	va_start(args, message);

	arg = va_arg(args, void *);
	value = reinterpret_cast<unsigned long>(arg);

	os << (arg != NULL && value >= COLORS_LEN ? "#INVALID COLOR#" : colors[value]) << "[LOG] - " << message << colors[0];

	arg = va_arg(args, int *);
	value = reinterpret_cast<unsigned long>(arg);

	if (arg == NULL || value == 0)
		os << LEND;
	else
		os << std::endl;
}