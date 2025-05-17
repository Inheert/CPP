/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:21:53 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 07:39:40 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

bool	Form::showTrace = false;

Form::Form( void ) : _name( "default" ), _requiredGradeSign( Bureaucrat::maxGrade ), _requiredGradeExecute( Bureaucrat::maxGrade ), _isSigned( false ) {}

Form::Form( std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec ): _name( name ),
		_requiredGradeSign( this->IsGradeValid( gradeToSign ) ? gradeToSign : Bureaucrat::maxGrade ),
		_requiredGradeExecute( this->IsGradeValid( gradeToExec ) ? gradeToExec : Bureaucrat::maxGrade ), _isSigned( false ) {}

Form::Form( Form const &other ): _name( other.GetName() ),
		_requiredGradeSign( this->IsGradeValid( other.GetRequiredGradeSign() ) ? other.GetRequiredGradeSign() : Bureaucrat::maxGrade ),
		_requiredGradeExecute( this->IsGradeValid( other.GetRequiredGradeExecute() ) ? other.GetRequiredGradeExecute() : Bureaucrat::maxGrade ), _isSigned( false ) {}

Form::~Form( void ) {}

bool	Form::IsGradeValid( unsigned int const grade ) const {
	try {
		if ( grade > Bureaucrat::minGrade )
			throw Form::GradeTooLowException();
		else if ( grade < Bureaucrat::maxGrade )
			throw Form::GradeTooHighException();

		return ( true );
	}
	catch( std::exception &e ) {
		LOGFLAGS( FL_ALL );
		LOGC( CRITICAL ) << e.what();
		LOGFLAGS( FL_NONE );

		return ( false );
	}
}

std::string const	Form::GetName( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return ( this->_name );
}

unsigned int	Form::GetRequiredGradeSign( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return ( this->_requiredGradeSign );
}

unsigned int Form::GetRequiredGradeExecute( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return( this->_requiredGradeExecute );
}

bool	Form::GetIsSigned( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return ( this->_isSigned );
}

void	Form::BeSigned( Bureaucrat const &signer ) {
	try {
		if ( signer.GetGrade() > this->_requiredGradeSign )
			throw Form::GradeTooLowException();
	}
	catch ( std::exception &e ) {
		LOGFLAGS( FL_ALL );
		LOGC( CRITICAL ) << e.what();
		LOGFLAGS( FL_NONE );

		LOGC( WARNING ) << signer.GetName() << " couldn't sign " << this->_name << " because his grade is too low.";
		return ;
	}

	if ( this->_isSigned ) {
		LOGC( WARNING ) << signer.GetName() << " couldn't sign " << this->_name << " because the form has already been signed.";
		return ;
	}

	this->_isSigned = true;
	LOGC( INFO ) << signer.GetName() << " signed " << this->_name;
}

Form	&Form::operator=( Form const &other ) {
	if ( this == &other )
		return ( *this );

	this->_isSigned = other.GetIsSigned();
	return ( *this );
}

std::ostream	&operator<<( std::ostream &os, Form const &add ) {
	if ( Form::showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	os << add.GetName() << ", form lowest grade to sign " << add.GetRequiredGradeSign() << ", lowest grade to execute " << add.GetRequiredGradeExecute() << ", is signed: " << add.GetIsSigned() << ".";
	return ( os );
}

char const	*Form::GradeTooLowException::what() const throw() {
	return ( "Grade is too low." );
}

char const		*Form::GradeTooHighException::what() const throw() {
	return ( "Grade is too high." );
}
