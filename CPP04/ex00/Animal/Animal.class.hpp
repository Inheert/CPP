#pragma once

#include <iostream>
#include <string>
#include "../utils/Log/Log.hpp"

class Animal {
	protected:
		std::string	_type;
		int			z;

	public:
		Animal( void );
		~Animal( void );

		Animal( const std::string type );
		Animal( const Animal &other );

		Animal	&operator=( const Animal &other );

		void	setType( const std::string newType );
		std::string	getType( void ) const;

		virtual void	makeSound( void ) const;
};
