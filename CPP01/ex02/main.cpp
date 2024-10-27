/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:03:22 by Théo              #+#    #+#             */
/*   Updated: 2024/10/27 08:37:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void ) {
	std::string	stringVar = "Hello World!";

	std::string	*stringPTR = &stringVar;

	std::string &stringREF = stringVar;

	std::cout << "stringVar address: "<< &stringVar << "" << std::endl;
	std::cout << "stringPTR address: "<< &stringPTR << "" << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl << std::endl;

	std::cout << "stringVar value: "<< stringVar << "" << std::endl;
	std::cout << "stringPTR value: "<< stringPTR << "" << std::endl;
	std::cout << "stringREF value:" << stringREF << "" << std::endl;

	return (0);
}
