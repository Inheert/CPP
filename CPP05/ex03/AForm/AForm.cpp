/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:21:53 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:48 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

bool	AForm::showTrace = false;

AForm::AForm( void ) : _name( "default" ), _requiredGradeSign( Bureaucrat::maxGrade ), _requiredGradeExecute( Bureaucrat::maxGrade ), _isSigned( false ) {}

AForm::AForm( std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec ): _name( name ),
		_requiredGradeSign( this->IsGradeValid( gradeToSign ) ? gradeToSign : Bureaucrat::maxGrade ),
		_requiredGradeExecute( this->IsGradeValid( gradeToExec ) ? gradeToExec : Bureaucrat::maxGrade ), _isSigned( false ) {}

AForm::AForm( AForm const &other ): _name( other.GetName() ),
		_requiredGradeSign( this->IsGradeValid( other.GetRequiredGradeSign() ) ? other.GetRequiredGradeSign() : Bureaucrat::maxGrade ),
		_requiredGradeExecute( this->IsGradeValid( other.GetRequiredGradeExecute() ) ? other.GetRequiredGradeExecute() : Bureaucrat::maxGrade ), _isSigned( false ) {}

AForm::~AForm( void ) {}

bool	AForm::IsGradeValid( unsigned int const grade ) const {
	try {
		if ( grade > Bureaucrat::minGrade )
			throw AForm::GradeTooLowException();
		else if ( grade < Bureaucrat::maxGrade )
			throw AForm::GradeTooHighException();

		return ( true );
	}
	catch( std::exception &e ) {
		LOGFLAGS( FL_ALL );
		LOGC( CRITICAL ) << e.what();
		LOGFLAGS( FL_NONE );

		return ( false );
	}
}

std::string const	AForm::GetName( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return ( this->_name );
}

unsigned int	AForm::GetRequiredGradeSign( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return ( this->_requiredGradeSign );
}

unsigned int AForm::GetRequiredGradeExecute( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return( this->_requiredGradeExecute );
}

bool	AForm::GetIsSigned( void ) const {
	if ( showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	return ( this->_isSigned );
}

void	AForm::BeSigned( Bureaucrat const &signer ) {
	try {
		if ( signer.GetGrade() > this->_requiredGradeSign )
			throw AForm::GradeTooLowException();
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
	LOGC( SUCCESS ) << signer.GetName() << " signed " << this->_name;
}

void	AForm::execute( Bureaucrat const &executor ) {
	try {
		if ( !this->_isSigned )
			throw AForm::FormNotSignedException();
		if ( this->_requiredGradeExecute < executor.GetGrade() )
			throw AForm::GradeTooLowException();
	}
	catch ( std::exception &e ) {
		LOGFLAGS( FL_ALL );
		LOGC( CRITICAL ) << e.what();
		LOGFLAGS( FL_NONE );
		LOGC( WARNING ) << executor.GetName() << " couldn't execute " << this->_name << " because his grade is too low.";
		return ;
	}
	this->MakeAction();
	LOGC( SUCCESS ) << executor.GetName() << " executed " << this->_name;
}

void	AForm::MakeAction( void ) {}

AForm	&AForm::operator=( AForm const &other ) {
	if ( this == &other )
		return ( *this );

	this->_isSigned = other.GetIsSigned();
	return ( *this );
}

std::ostream	&operator<<( std::ostream &os, AForm const &add ) {
	if ( AForm::showTrace ) {
		LOGFLAGS( FL_ALL );
		LOGC( DEBUG ) << "Trace";
		LOGFLAGS( FL_NONE );
	}

	os << add.GetName() << ", form lowest grade to sign " << add.GetRequiredGradeSign() << ", lowest grade to execute " << add.GetRequiredGradeExecute() << ", is signed: " << add.GetIsSigned() << ".";
	return ( os );
}

char const	*AForm::GradeTooLowException::what() const throw() {
	return ( "Grade is too low." );
}

char const	*AForm::GradeTooHighException::what() const throw() {
	return ( "Grade is too high." );
}

char const	*AForm::FormNotSignedException::what() const throw() {
	return ( "The form has not been signed." );
}
