/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:46:38 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/14 09:41:08 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ClapTrap/ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	private:

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &other );
		virtual	~FragTrap( void );

		FragTrap &operator=( const FragTrap &other );

		void	highFivesGuys( void );
};
