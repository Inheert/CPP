/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:07:55 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 07:20:59 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "../utils/Log/Log.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		unsigned int const	_requiredGradeSign;
		unsigned int const	_requiredGradeExecute;

		bool				_isSigned;

		bool				IsGradeValid( unsigned int const grade ) const;
	public:
		static bool			showTrace;

		Form( void );
		Form( std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec );
		Form( Form const &other );

		~Form( void );

		std::string const	GetName( void ) const;
		unsigned int		GetRequiredGradeSign( void ) const;
		unsigned int		GetRequiredGradeExecute( void ) const;
		bool				GetIsSigned( void ) const;

		void				BeSigned( Bureaucrat const &signer );

		Form				&operator=( Form const &other );

		class	GradeTooLowException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class	GradeTooHighException : public std::exception {
			public:
				virtual char const *what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &os, Form const &add );
