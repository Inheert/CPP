/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:12:05 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 13:48:59 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../IMateriaSource/IMateriaSource.hpp"

class MateriaSource : public virtual IMateriaSource
{
	private:
		AMateria*	_learned[ 4 ];

	public:
		MateriaSource( void );
		~MateriaSource( void );

		MateriaSource( MateriaSource const & other );
		MateriaSource& operator=( MateriaSource const & other );

		void copyData( MateriaSource const & other );

		// Inherited method
		void learnMateria( AMateria* m );
		AMateria* createMateria( std::string const & type );
};
