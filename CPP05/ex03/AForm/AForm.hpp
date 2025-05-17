/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:07:55 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:41 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "../utils/Log/Log.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		std::string			_target;
		unsigned int const	_requiredGradeSign;
		unsigned int const	_requiredGradeExecute;

		bool				_isSigned;

		bool				IsGradeValid( unsigned int const grade ) const;
		virtual void		MakeAction( void );

	public:
		static bool			showTrace;

		AForm( void );
		AForm( std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec );
		AForm( AForm const &other );

		virtual ~AForm( void );

		std::string const	GetName( void ) const;
		unsigned int		GetRequiredGradeSign( void ) const;
		unsigned int		GetRequiredGradeExecute( void ) const;
		bool				GetIsSigned( void ) const;

		void				BeSigned( Bureaucrat const &signer );
		void				execute( Bureaucrat const &executor );


		virtual AForm		*clone( void ) = 0;
		AForm				&operator=( AForm const &other );

		class	GradeTooLowException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class	GradeTooHighException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class	FormNotSignedException : public std::exception {
			public:
				virtual char const *what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &os, AForm const &add );
