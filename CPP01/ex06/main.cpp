/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:37:47 by Théo              #+#    #+#             */
/*   Updated: 2024/10/22 06:31:30 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter/HarlFilter.hpp"

int	main( int argc, char **argv ) {
	(void)argc; (void)argv;
	if (argc != 2) {
		std::cout << "Error: 1 argument is required." << std::endl;
		return (0);
	}
	HarlFilter	harlFilter = HarlFilter();
	harlFilter.complain(argv[1]);
	return (0);
}
