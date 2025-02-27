/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:32:36 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 14:08:11 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/Log/Log.hpp"
#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "Brain/Brain.hpp"

int	main( void ) {
	unsigned int	tblLen = 10;

	Animal	*animals[ tblLen ];

	for ( unsigned int i = 0; i < tblLen ; i++ ) {
		if ( i < tblLen * 0.5 )
			animals[ i ] = new Cat();
		else
			animals[ i ] = new Dog();
		animals[ i ]->makeSound();
	}

	Brain*	brain = animals[ 0 ]->getBrain();

	LOG() << &brain;
	brain->setIdeas( "Awesome idea", 0 );

	Brain* 	brain2 = animals[ ( int )( tblLen * 0.5 + 1 ) ]->getBrain();

	for ( unsigned int i = 0; i < 100; i++ )
		brain2->setIdeas( "Awful idea", i );

	LOG() << "Cat1 idea: " << brain->getIdeas()[ 0 ];
	LOG() << "Cat2 idea: " << brain2->getIdeas()[ 0 ];

	LOG() << "Brain1 ptr adress: " << &brain;
	LOG() << "Brain2 ptr adress: " << &brain2;

	brain = brain2;

	LOG() << "Cat1 idea: " << brain->getIdeas()[ 0 ];
	LOG() << "Cat2 idea: " << brain2->getIdeas()[ 0 ];

	LOG() << "Brain1 ptr adress: " << &brain;
	LOG() << "Brain2 ptr adress: " << &brain2;
	// std::cout << brain[ 0 ];

	for ( unsigned int i = 0; i < tblLen; i++ )
		delete animals[ i ];

	return ( 0 );
}
