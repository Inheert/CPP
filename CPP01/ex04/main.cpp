/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:01:38 by Théo              #+#    #+#             */
/*   Updated: 2024/10/27 15:15:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(char **argv, std::string str) {
	std::ofstream	file;
	int				pos;

	file.open((std::string(argv[1]) + ".replace").c_str());
	if (file.fail()) {
		std::cout << "Error: a problem occur while using ofstream." << std::endl;
		return (1);
	}
	for (int i = 0; i < (int)str.size(); i++) {
		pos = str.find(argv[2], i);
		if (pos != -1 && pos == i) {
			file << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			file << str[i];
	}
	file.close();
	return (0);
}

int	main( int argc, char **argv ) {
	std::ifstream	file;
	std::string		str;
	char			c;

	if ( argc != 4 ) {
		std::cout << "This program only take 3 arguments." << std::endl;
		return (1);
	}
	file.open(argv[1]);
	if (file.fail()) {
		std::cout << "Error: " << argv[1] << " no such file or directory." << std::endl;
		return (1);
	}
	while (!file.eof() && file >> std::noskipws >> c)
		str += c;
	file.close();
	return (replace(argv, str));
}
