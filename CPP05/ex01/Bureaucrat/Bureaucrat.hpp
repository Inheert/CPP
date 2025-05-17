/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:07:53 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 12:30:11 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "../utils/Log/Log.hpp"
#include "../Form/Form.hpp"

class Form;

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

		void				SignForm( Form &form );

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
