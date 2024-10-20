/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:03:22 by Théo              #+#    #+#             */
/*   Updated: 2024/10/19 12:14:11 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void ) {
	std::string	stringVar = "Hello World!";

	std::string	*stringPTR = &stringVar;

	std::string &stringREF = stringVar;
	
	std::cout << "stringVar address: "<< &stringVar << "\n";
	std::cout << "stringPTR address: "<< &stringPTR << "\n";
	std::cout << "stringREF address: " << &stringREF << "\n\n";

	std::cout << "stringVar value: "<< stringVar << "\n";
	std::cout << "stringPTR value: "<< stringPTR << "\n";
	std::cout << "stringREF value:" << stringREF << "\n";

	return (0);
}
