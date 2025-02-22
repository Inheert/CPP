#include "Cat.class.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {}

Cat::~Cat( void ) {}

Cat::Cat( const Cat &other ) : Animal( other ) {
	LOG() << this->_type;
}

Cat	&Cat::operator=( const Cat &other ) {
	this->_type = other._type;

	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	return ( *this );
}

void	Cat::makeSound( void ) const {
	LOG() << "Miaou";
}
