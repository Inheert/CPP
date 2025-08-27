/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 07:56:08 by tclaereb          #+#    #+#             */
/*   Updated: 2025/08/27 13:01:15 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AForm/AForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"

#include <string>

class Intern {
	public:
		Intern( void );
		Intern( const Intern &other );

		~Intern( void );

		Intern	&operator=( const Intern &other );

		AForm	*MakeForm( const std::string name, const std::string target );

		class	FormNotFound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
