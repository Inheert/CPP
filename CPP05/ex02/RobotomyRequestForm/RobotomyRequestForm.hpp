/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:54:33 by tclaereb          #+#    #+#             */
/*   Updated: 2025/04/22 07:01:16 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../AForm/AForm.hpp"
#include "../utils/Log/Log.hpp"

#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		const std::string	_target;

		void	MakeAction( void );

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &other );
		~RobotomyRequestForm( void );

		RobotomyRequestForm	&operator=( const RobotomyRequestForm &other );
};
