/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:20:45 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/22 07:13:03 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AForm/AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
		const std::string	_target;

		void MakeAction( void );

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( PresidentialPardonForm &other );

		~PresidentialPardonForm( void );

		PresidentialPardonForm	&operator=( const PresidentialPardonForm &other );
};
