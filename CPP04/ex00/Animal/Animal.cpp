#include "Animal.class.hpp"

Animal::Animal( void ) : _type( "default" ) {
	LOGC( GREEN ) << this->_type << " default constructor.";
}


Animal::~Animal( void ) {
	LOGC( RED ) << this->_type << " default destructor.";
}

Animal::Animal( const std::string type ) : _type( type ) {
	LOGC( GREEN ) << this->_type << " constructor.";
}

Animal::Animal( const Animal &other ) {
	this->_type = other._type;

	LOGC( GREEN ) << this->_type << " copy constructor.";
}

Animal	&Animal::operator=( const Animal &other ) {
	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	this->_type = other._type;

	return ( *this );
}

void	Animal::setType( const std::string newType ) {
	this->_type = newType;
}

std::string	Animal::getType( void ) const {
	return ( this->_type );
}

void	Animal::makeSound( void ) const {}
