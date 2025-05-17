/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/22 07:51:40 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

#include "utils/Log/Log.hpp"

#include <cstdlib>

int	main() {
	srand( time( NULL ) );

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "ShrubberyCreationForm check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 10; i++ ) {
		Bureaucrat	bur( "Gurranq", rand() % Bureaucrat::minGrade );
		ShrubberyCreationForm form( "Bestial Sanctum" );

		LOGC( INFO ) << "Bureaucrat data: " << bur;
		LOGC( INFO ) << "Form data: " << form;
		LOGC( INFO ) << "Signature:";
		bur.SignForm( form );
		LOGC( INFO ) << "Execution:";
		bur.executeForm( form );
		std::cout << "\r\n";
	}

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "RobotomyRequestForm check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 10; i++ ) {
		Bureaucrat	bur( "Gurranq", rand() % Bureaucrat::minGrade );
		RobotomyRequestForm form( "Bestial Sanctum" );

		LOGC( INFO ) << "Bureaucrat data: " << bur;
		LOGC( INFO ) << "Form data: " << form;
		LOGC( INFO ) << "Signature:";
		bur.SignForm( form );
		LOGC( INFO ) << "Execution:";
		bur.executeForm( form );
		std::cout << "\r\n";
	}

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "PresidentialPardonForm check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 10; i++ ) {
		Bureaucrat	bur( "Gurranq", rand() % Bureaucrat::minGrade );
		PresidentialPardonForm form( "Bestial Sanctum" );

		LOGC( INFO ) << "Bureaucrat data: " << bur;
		LOGC( INFO ) << "Form data: " << form;
		LOGC( INFO ) << "Signature:";
		bur.SignForm( form );
		LOGC( INFO ) << "Execution:";
		bur.executeForm( form );
		std::cout << "\r\n";
	}

	PresidentialPardonForm	a( "Chenillepan" );
	Bureaucrat	bur( "Gregory", 2 );

}
