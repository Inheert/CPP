#pragma once

#include "../Animal/Animal.class.hpp"

class Cat : public virtual Animal
{
	public:
		Cat( void );
		~Cat( void );

		Cat( const Cat &other );
		Cat	&operator=( const Cat &other );

		virtual void	makeSound( void ) const;
};
