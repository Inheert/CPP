/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/20 11:24:27 by tclaereb         ###   ########.fr       */
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
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat	bur( "Bubur", 150 );
	rrf = someRandomIntern.MakeForm("robotomy request", "Bender");
	bur.SignForm( *rrf );
	bur.executeForm( *rrf );
	delete rrf;
}
