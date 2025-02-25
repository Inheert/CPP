#pragma once

#include "../A_Animal/A_Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public virtual A_Animal
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
