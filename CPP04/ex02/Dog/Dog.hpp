#pragma once

#include "../A_Animal/A_Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public virtual A_Animal
{
	private:
		Brain*	_brain;

	public:
		Dog( void );
		~Dog( void );

		Dog( const Dog &other );

		Dog	&operator=( const Dog &other );

		virtual void	makeSound( void ) const;

		virtual Brain*	getBrain( void ) const;
};
