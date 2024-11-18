/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:17:02 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/18 11:25:22 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib> // For usleep (POSIX) or Sleep (Windows)

void printProgress(int current, int total) {
	std::cout <<"\r";

	for (int i = 0; i < current; i++) {
		std::cout << "✅ ";
	}
	for (int i = current; i < total; i++) {
		std::cout << "⬛ ";
	}
	std::cout << "(" << current << "/" << total << ")" << std::flush;
}

// Cross-platform sleep function for C++98
void sleepMilliseconds(int milliseconds) {
#ifdef _WIN32
	Sleep(milliseconds); // Windows
#else
	usleep(milliseconds * 1000); // POSIX
#endif
}

int main(int argc, char **argv) {
	if (argc < 2)
		return (0);

	std::cout << "\033[1A";
	std::cout << "\033[2K";

	int	totalFiles = std::atoi(argv[1]);
	int	count = std::atoi(argv[2]);

	for (int i = 1; i <= count; ++i) {
		printProgress(i, totalFiles);
		sleepMilliseconds(200);
	}
	std::cout << argv[3] << argv[4];
	std::cout << std::endl;
	return (0);
}
