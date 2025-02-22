#pragma once

#include "../Animal/Animal.class.hpp"

class Dog : public virtual Animal
{
	public:
		Dog( void );
		~Dog( void );

		Dog( const Dog &other );

		Dog	&operator=( const Dog &other );

		virtual void	makeSound( void ) const;
};
