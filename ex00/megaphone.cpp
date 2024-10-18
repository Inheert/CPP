/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:42:22 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 09:27:00 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Megaphone {
	public:
		Megaphone(int argc, char **argv);
};

Megaphone::Megaphone(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return ;
	}
	for (int i = 1; i < argc; i++)
		std::cout << argv[i];
	std::cout << "\n";
}

int	main(int argc, char **argv)
{
	Megaphone	megaphone(argc, argv);
}
