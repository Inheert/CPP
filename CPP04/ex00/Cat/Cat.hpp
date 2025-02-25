/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:27:00 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 07:27:00 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Animal/Animal.hpp"

class Cat : public virtual Animal
{
	public:
		Cat( void );
		virtual ~Cat( void );

		Cat( const Cat &other );
		Cat	&operator=( const Cat &other );

		virtual void	makeSound( void ) const;
};
