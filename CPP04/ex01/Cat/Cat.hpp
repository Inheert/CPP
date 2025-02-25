#pragma once

#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public virtual Animal
{
	private:
		Brain*	_brain;

	public:
		Cat( void );
		virtual ~Cat( void );

		Cat( const Cat &other );
		Cat	&operator=( const Cat &other );

		virtual void	makeSound( void ) const;

		virtual Brain*	getBrain( void ) const;
};
