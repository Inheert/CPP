/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:55:15 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 14:13:58 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"

#include "utils/Log/Log.hpp"

int	main() {
	PresidentialPardonForm	a( "Chenillepan" );
	Bureaucrat	bur( "Gregory", 2 );

	a.BeSigned( bur );
	bur.executeForm( a );
	a.execute( bur );

	a.BeSigned( bur );
	bur.executeForm( a );
	a.execute( bur );

	RobotomyRequestForm	rob;

	bur.SignForm( rob );
	bur.executeForm( rob );
}
