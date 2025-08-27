/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/08/27 13:56:03 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Intern/Intern.hpp"

#include "utils/Log/Log.hpp"

#include <cstdlib>

int	main() {
	srand( time( NULL ) );
	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Intern creation check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	const unsigned int	size = 5;
	const std::string	formName[ size ] = { "robotomy request", "president paron", "president pardon", "shrubbery creation", "erggeg" };

	for ( unsigned int i = 0; i < 20; i++ ) {
		Intern someRandomIntern;
		AForm* form;
		form = someRandomIntern.MakeForm( formName[ rand() % size ], "Bender" );

		if ( !form )
			continue ;
		Bureaucrat	bur( "Remi", rand() % Bureaucrat::minGrade );
		LOGC( INFO ) << "Bureaucrat info: " << bur;
		LOGC( INFO ) << "Form info: " << *form;
		bur.SignForm( *form );
		bur.executeForm( *form );
		std::cout << LEND;
		delete form;
	}
}
