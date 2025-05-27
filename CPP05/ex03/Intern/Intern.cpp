/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 07:56:17 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/20 11:21:09 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "../utils/Log/Log.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern &other ) { ( void )other; }

Intern::~Intern( void ) {}

Intern	&Intern::operator=( const Intern &other ) {
	if ( this == &other )
		return ( *this );

	return ( *this );
}

AForm	*Intern::MakeForm( const std::string name, const std::string target ) {
	const std::string	ids[ 3 ] = { "robotomy request", "president pardon", "shrubbery creation" };

	unsigned int i = -1;
	while ( ++i < 3 ) {
		if ( ids[ i ] == name )
			break ;
	}

	switch ( i ) {
		case 0:
			LOGC( INFO ) << "Intern creates " << ids[ i ];
			return ( new RobotomyRequestForm( target ) );
		case 1:
			LOGC( INFO ) << "Intern creates " << ids[ i ];
			return ( new PresidentialPardonForm( target ) );
		case 2:
			LOGC( INFO ) << "Intern creates " << ids[ i ];
			return ( new ShrubberyCreationForm( target ) );
	}

	return ( NULL );
}
