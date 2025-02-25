#include "Dog.hpp"

Dog::Dog( void ) : A_Animal( "Dog" ), _brain( new Brain ) {
	LOGC( GREEN ) << "Dog default constructor.";
}

Dog::~Dog( void ) {
	LOGC( RED ) << "Dog destructor.";

	delete this->_brain;
}

Dog::Dog( const Dog &other ) : A_Animal( other ) {
	LOGC( GREEN ) << "Dog copy constructor.";

	this->_brain = other._brain;
}

Dog	&Dog::operator=( const Dog &other ) {
	A_Animal::operator=( other );

	LOGC( YELLOW ) << this->_type << " assignation overload called.";

	this->_brain = other._brain;
	return ( *this );
}

void	Dog::makeSound() const {
	LOG() << "Woof!";
}

Brain*	Dog::getBrain( void ) const {
	return ( this->_brain );
}
