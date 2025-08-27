/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:57:40 by tclaereb          #+#    #+#             */
/*   Updated: 2025/08/27 12:39:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm( "RobotomyRequestForm", 72, 45 ), _target( "noTarget" ) {}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm( "RobotomyRequestForm", 72, 45 ), _target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm( "RobotomyRequestForm", 72, 45 ), _target( other._target ) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
	if ( this == &other )
		return ( *this );

	return ( *this );
}

void	RobotomyRequestForm::MakeAction( void ) {
	srand( time( NULL ) );

	unsigned int	result = rand() % 10;

	if ( result >= 5 )
		LOGC( SUCCESS ) << this->_target << "have been robotomized.";
	else if ( result < 5 )
		LOGC( WARNING ) << "Robotomatization failed.";
}
