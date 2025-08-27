/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:07:43 by tclaereb          #+#    #+#             */
/*   Updated: 2025/08/26 17:19:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

unsigned int const Bureaucrat::minGrade = 150;
unsigned int const Bureaucrat::maxGrade = 1;

Bureaucrat::Bureaucrat( void ) : _name( "default" ), _grade( Bureaucrat::minGrade ) {}

Bureaucrat::Bureaucrat( std::string const name, unsigned int grade ) : _name( name ) {
	if ( !this->_SetGrade( grade ) )
		this->_SetGrade( minGrade );
}

Bureaucrat::Bureaucrat( Bureaucrat const &other ) : _name( other.GetName() ) {
	if ( !this->_SetGrade( other.GetGrade() ) )
		this->_SetGrade( minGrade );
}

Bureaucrat::~Bureaucrat( void ) {}

bool	Bureaucrat::_SetGrade( unsigned int const newGrade ) {
	try {
		if ( newGrade > minGrade)
			throw Bureaucrat::GradeTooLowException();
		else if ( newGrade < maxGrade )
			throw Bureaucrat::GradeTooHighException();

		this->_grade = newGrade;

		return ( true );
	}
	catch ( std::exception & e ) {
		LOGFLAGS( FL_ALL );
		LOGC( RED ) << e.what();
		LOGFLAGS( FL_NONE );

		return ( false );
	}
}

std::string const	Bureaucrat::GetName( void ) const {
	return ( this->_name );
}

unsigned int	Bureaucrat::GetGrade( void ) const {
	return ( this->_grade );
}

void	Bureaucrat::IncrementGrade( void ) {
	this->_SetGrade( this->_grade - 1 );
}

void	Bureaucrat::DecrementGrade( void ) {
	this->_SetGrade( this->_grade + 1 );
}

void	Bureaucrat::SignForm( Form &form ) {
	form.BeSigned( *this );
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &other ) {
	if ( this == &other )
		return ( *this );

	this->_SetGrade( other.GetGrade() );
	return ( *this );
}

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &add ) {
	os << add.GetName() << ", bureaucrat grade " << add.GetGrade() << ".";
	return ( os );
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
	return ( "Grade is too low." );
}

char const * Bureaucrat::GradeTooHighException::what() const throw() {
	return ( "Grade is too high." );
}
