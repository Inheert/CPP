/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:54:33 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/21 14:14:36 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm/AForm.hpp"
#include "../utils/Log/Log.hpp"

#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;

		void	MakeAction( void );
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const target );
		RobotomyRequestForm( RobotomyRequestForm const &other );
		~RobotomyRequestForm( void );

		RobotomyRequestForm	&operator=( RobotomyRequestForm const &other );
};
