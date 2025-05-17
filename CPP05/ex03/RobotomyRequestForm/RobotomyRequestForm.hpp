/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:54:33 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/29 12:47:29 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AForm/AForm.hpp"
#include "../utils/Log/Log.hpp"

#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;

		void	MakeAction( void );

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &other );
		~RobotomyRequestForm( void );

		RobotomyRequestForm		*clone( void );
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &other );
};
