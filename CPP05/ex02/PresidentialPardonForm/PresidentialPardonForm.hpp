/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:20:45 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 13:56:28 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "../AForm/AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
		std::string const	_target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm &other );

		~PresidentialPardonForm( void );

		PresidentialPardonForm&	operator=( PresidentialPardonForm &other );

		void MakeAction( void );
};
