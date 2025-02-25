#include "Cat.hpp"

Cat::Cat( void ) : A_Animal( "Cat" ), _brain( new Brain ) {
	LOGC( GREEN ) << "Cat default constructor.";
}

Cat::~Cat( void ) {
	LOGC( RED ) << "Cat destructor.";

	delete this->_brain;
}

Cat::Cat( const Cat &other ) : A_Animal( other ) {
	LOGC( GREEN ) << "Cat copy constructor.";

	this->_brain = other._brain;
}

Cat	&Cat::operator=( const Cat &other ) {
	A_Animal::operator=( other );

	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	this->_brain = other._brain;

	return ( *this );
}

void	Cat::makeSound( void ) const {
	LOG() << "Miaou";
}

Brain*	Cat::getBrain( void ) const {
	return ( this->_brain );
}
