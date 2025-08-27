#include "Bureaucrat.hpp"

unsigned int const Bureaucrat::minGrade = 150;
unsigned int const Bureaucrat::maxGrade = 1;

Bureaucrat::Bureaucrat( void ) : _name( "default" ), _grade( Bureaucrat::minGrade ) {}

Bureaucrat::Bureaucrat( std::string const name, unsigned int grade ) : _name( name ) {
	if ( !this->_SetGrade( grade ) ) {
		LOGC( INFO ) << "Trying to initialize a bureaucrat with an invalid grade, lowest grade will be defined.";
		this->_SetGrade( minGrade );
	}
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
		LOGC( SUCCESS ) << "Grade is valid. (" << newGrade << ")";

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
