/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/22 07:26:35 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/Form.hpp"

#include <cstdlib>

int	main() {
	srand( time( NULL ) );

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Grade range check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	LOGC( INFO ) << "BureauCrat Minimum: " << Bureaucrat::minGrade;
	LOGC( INFO ) << "Bureaucrat Maximum: " << Bureaucrat::maxGrade;
	LOGC( INFO ) << "Form Minimum: " << Bureaucrat::minGrade;
	LOGC( INFO ) << "Form Maximum: " << Bureaucrat::maxGrade  << LEND;

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Getter check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Form	example( "exampleForm", 140, 2 );

	Form::showTrace = true;
	std::string	tmp = example.GetName();
	LOGC( INFO ) << "Name: " << tmp;
	tmp = example.GetRequiredGradeSign();
	LOGC( INFO ) << "Required grade to sign: " << tmp;
	tmp = example.GetRequiredGradeExecute();
	LOGC( INFO ) << "Required grade to execute: " << tmp;
	tmp = example.GetIsSigned();
	LOGC( INFO ) << "Is form signed: " << tmp << LEND;
	Form::showTrace = false;

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "'<<' overlad check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Form::showTrace = true;
	std::ostringstream	oss;
	oss << example;
	LOGC( INFO ) << oss.str();
	Form::showTrace = false;

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Instancation of valid and invalid Form check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 200; i++ ) {
		void	*base = NULL;
		unsigned int grade = ( ( unsigned long long )&base >> ( i * 8 ) ) & 0xFF;
		grade = grade % Bureaucrat::minGrade * 2;

		LOGC( INFO ) << "Grade: " << grade << " should work: " << ( grade > Bureaucrat::minGrade || grade < Bureaucrat::maxGrade ? "NO" : "YES" );
		Bureaucrat	test( "name", grade );
		LOGC( INFO ) << test << LEND;
	}

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Bureaucrat sign form check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 20; i++ ) {
		unsigned int grade = rand() % Bureaucrat::minGrade;
		unsigned int gradeToSign = rand() % Bureaucrat::minGrade;
		unsigned int gradeToExecute = rand() % Bureaucrat::minGrade;

		LOGC( INFO ) << "Bureaucrat grade: " << grade;
		LOGC( INFO ) << "Form required grade to sign: " << gradeToSign;
		LOGC( INFO ) << "Form required grade to execute: " << gradeToExecute;
		LOGC( DEBUG ) << "Should be able to sign: " << ( grade < gradeToSign ? "YES" : "NO" );
		LOGC( DEBUG ) << "Should be able to execute: " << ( grade < gradeToExecute ? "YES" : "NO" );

		Bureaucrat	bur( "Bureaucrat", grade );
		Form		form( "AwesomeForm", gradeToSign, gradeToExecute );

		bur.SignForm( form );
		bur.SignForm( form );
		LOGC( WHITE ) << "-" << LEND;
	}
}
