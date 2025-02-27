/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:32:36 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 14:29:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/Log/Log.hpp"
#include "AAnimal/AAnimal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "Brain/Brain.hpp"

int	main( void ) {
	Dog a = Dog();
	Cat b = Cat();

	AAnimal *c = new Dog();

	// A_Animal d;

	delete c;
	return ( 0 );
}
