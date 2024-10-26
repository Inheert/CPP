/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:27:55 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/26 14:28:29 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

Megaphone::Megaphone(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return ;
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<unsigned char>(toupper((argv[i][j])));
	}
	std::cout << std::endl;
}
