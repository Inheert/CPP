/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/29 13:12:27 by tclaereb         ###   ########.fr       */
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
	rrf = someRandomIntern.MakeForm("robotogrgmy request", "Bender");
	std::cout << &rrf << std::endl;
	std::cout << rrf << std::endl;
	delete rrf;
}
