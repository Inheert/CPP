/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:08:34 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 05:07:35 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WrongAnimal/WrongAnimal.hpp"

class	WrongCat : public virtual WrongAnimal
{
	public:
		WrongCat( void );
		virtual ~WrongCat( void );

		WrongCat( WrongCat const &other );
		WrongCat&	operator=( WrongCat const &other );
};

