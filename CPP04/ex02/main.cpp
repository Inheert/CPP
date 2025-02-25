/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:32:36 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/25 09:34:26 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/Log/Log.hpp"
#include "A_Animal/A_Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "Brain/Brain.hpp"

int	main( void ) {
	Dog a = Dog();
	Cat b = Cat();

	A_Animal *c = new Dog();

	// A_Animal d;

	delete c;
	return ( 0 );
}
