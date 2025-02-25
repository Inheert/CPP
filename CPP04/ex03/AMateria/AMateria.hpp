/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:19:42 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 11:22:52 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AMateria
{
	protected:

	public:
		AMateria( std::string const & type );
		~AMateria( void );

		AMateria( AMateria const & other );
		AMateria& operator=( AMateria const & other );

		virtual AMateria*	clone() const = 0;
		virtual void		use	( ICharacter& target );
}
