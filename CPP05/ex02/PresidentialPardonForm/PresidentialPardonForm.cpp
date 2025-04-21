/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:24:31 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 14:12:03 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( "noTarget" ) {}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &other ) : AForm( other ), _target( other._target ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm &other ) {
	if ( this == &other )
		return ( *this );

	return ( *this );
}

void	PresidentialPardonForm::MakeAction( void ) {
	LOGC( INFO ) << this->_target << " has been pardoned by Zaphod Beeblebrox.";
}
