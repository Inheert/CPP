/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/08/25 08:48:23 by tclaereb         ###   ########.fr       */
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

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Getter check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	Form	example( "exampleForm", 140, 2 );

	LOGC( INFO ) << "Name: " << example.GetName();
	LOGC( INFO ) << "Required grade to sign: " << example.GetRequiredGradeSign();
	LOGC( INFO ) << "Required grade to execute: " << example.GetRequiredGradeExecute();
	LOGC( INFO ) << "Is form signed: " << example.GetIsSigned();

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "'<<' overload check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	std::ostringstream	oss;
	oss << example;
	LOGC( INFO ) << oss.str();

	std::cout << LEND << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Instancation of valid and invalid Form check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 5; i++ ) {
		unsigned int gradeToSign = rand() % Bureaucrat::minGrade * 2;
		unsigned int gradeToExecute = rand() % Bureaucrat::minGrade * 2;

		bool shouldWork = ( gradeToSign > Bureaucrat::minGrade || gradeToSign < Bureaucrat::maxGrade ) && ( gradeToExecute > Bureaucrat::minGrade || gradeToExecute < Bureaucrat::maxGrade );

		LOGC( INFO ) << "Grade to sign: " << gradeToSign << ", grade to execute: " << gradeToExecute << ", should work: " << ( shouldWork ? "YES" : "NO" );
		Form	test( "FormExample", gradeToSign, gradeToExecute );
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
