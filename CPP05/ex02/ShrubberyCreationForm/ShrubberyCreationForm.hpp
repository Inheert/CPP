/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 06:44:54 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/22 07:11:08 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm/AForm.hpp"
#include "../utils/Log/Log.hpp"

#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;

		void	MakeAction( void );

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &other );
		ShrubberyCreationForm( const std::string target );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other );
};
