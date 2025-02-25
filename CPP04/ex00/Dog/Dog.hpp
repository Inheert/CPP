/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:26:50 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 07:26:51 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Animal/Animal.hpp"

class Dog : public virtual Animal
{
	public:
		Dog( void );
		~Dog( void );

		Dog( const Dog &other );

		Dog	&operator=( const Dog &other );

		virtual void	makeSound( void ) const;
};
