/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 06:16:32 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 13:15:04 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/Log/Log.hpp"

#include "AMateria/AMateria.hpp"
#include "Ice/Ice.hpp"
#include "Cure/Cure.hpp"

#include "ICharacter/ICharacter.hpp"
#include "Character/Character.hpp"

#include "MateriaSource/MateriaSource.hpp"

void	unequipCharacter( int idx, Character& target ) {
	if ( idx < 0 || idx > 3 )
		return ;

	AMateria* mat = target.getInventory()[ idx ];
	target.unequip( idx );

	if ( !mat )
		return;

	delete mat;
}

int	main( void ) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
