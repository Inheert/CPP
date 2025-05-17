#pragma once

#include <iostream>
#include <string>

#include "../utils/Log/Log.hpp"

class Bureaucrat {
	private:
		std::string const	_name;
		unsigned int		_grade;

		bool	_SetGrade( unsigned int const newGrade );

	public:
		static unsigned int const	minGrade;
		static unsigned int const	maxGrade;

		Bureaucrat( void );
		Bureaucrat( std::string const name, unsigned int grade );
		Bureaucrat( Bureaucrat const &other );
		~Bureaucrat( void );

		std::string const	GetName( void ) const;
		unsigned int		GetGrade( void ) const;

		void				IncrementGrade( void );
		void				DecrementGrade( void );

		Bureaucrat			&operator=( Bureaucrat const &other );

		class	GradeTooLowException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class	GradeTooHighException : public std::exception {
			public:
				virtual char const *what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &add );
