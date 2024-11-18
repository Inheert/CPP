/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:52:35 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/18 06:09:15 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string colors[15] = {
    "\033[0m", // DEFAULT
    "\033[1;31m", // RED
    "\033[1;32m", // GREEN
    "\033[1;33m", // YELLOW
};

void	log(int level, std::ostream &os, const std::string &message) {
	os << colors[level] << message << colors[0] << std::endl;
}
