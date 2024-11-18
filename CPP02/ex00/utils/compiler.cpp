/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:17:02 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/18 13:22:35 by Théo             ###   ########.fr       */
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

	printProgress(count, totalFiles);
	std::cout << std::endl;
	return (0);
}
