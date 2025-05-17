/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:24:31 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/29 09:14:17 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( "noTarget" ) {}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &other ) : AForm( other ), _target( other._target ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm	*PresidentialPardonForm::clone( void ) {
	PresidentialPardonForm	*n = new PresidentialPardonForm( *this );
	return ( n );
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	if ( this == &other )
		return ( *this );

	return ( *this );
}

void	PresidentialPardonForm::MakeAction( void ) {
	LOGC( INFO ) << this->_target << " has been pardoned by Zaphod Beeblebrox.";
}
