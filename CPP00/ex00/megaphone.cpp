/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:42:22 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/30 07:55:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<unsigned char>(toupper((argv[i][j])));
	}
	std::cout << std::endl;
}
