/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:19 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/28 14:32:37 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>

// void	log(std::string &msg, ...) {
// 	std::cout << msg;
// }

#include "utils/Log/Log.hpp"

int	main( void ) {
	LOGC(BLUE) << "ld" << 5.45f << LEND;
	//LOG.header_len = 10;
	LOG() << "efoibwe" << LEND;
	return (0);
}
