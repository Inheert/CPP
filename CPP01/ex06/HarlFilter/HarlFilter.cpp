/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:40:06 by Théo              #+#    #+#             */
/*   Updated: 2024/10/22 06:34:33 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

HarlFilter::HarlFilter( void ) {}

HarlFilter::~HarlFilter( void ) {}

void	HarlFilter::_display_complain( int level ) {
	void		(HarlFilter::*ptr_complain[4])( void ) = {&HarlFilter::debug, &HarlFilter::info, &HarlFilter::warning, &HarlFilter::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = level; i < 4; i++) {
		(this->*ptr_complain[i])();
		if (i != 3)
			std::cout << std::endl;
	}
}

void	HarlFilter::complain( std::string level ) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			levelIdx = -1;

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			levelIdx = i;
			break ;
		}
	}
	switch (levelIdx) {
		case 0:
			this->_display_complain(0);
			break ;
		case 1:
			this->_display_complain(1);
			break ;
		case 2:
			this->_display_complain(2);
			break ;
		case 3:
			this->_display_complain(3);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

void	HarlFilter::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	HarlFilter::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	HarlFilter::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	HarlFilter::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
