#include "Dog.class.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {}

Dog::~Dog( void ) {}

Dog::Dog( const Dog &other ) : Animal( other ) {
	this->_type = other._type;
}

Dog	&Dog::operator=( const Dog &other ) {
	this->_type = other._type;

	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	return ( *this );
}

void	Dog::makeSound() const {
	LOG() << "Woof!";
}
