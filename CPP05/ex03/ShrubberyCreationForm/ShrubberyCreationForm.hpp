/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 06:44:54 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/29 12:47:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AForm/AForm.hpp"
#include "../utils/Log/Log.hpp"

#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

		void	MakeAction( void );

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &other );
		ShrubberyCreationForm( const std::string target );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm		*clone( void );
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other );
};
