/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:19 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/22 17:28:22 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>

// void	log(std::string &msg, ...) {
// 	std::cout << msg;
// }

#include "utils/Log/Log.hpp"
#include "Animal/Animal.class.hpp"
#include "Dog/Dog.class.hpp"
#include "Cat/Cat.class.hpp"

int	main( void ) {
	// HEADERWIDTH(50);
	// ENABLEHEADER(true);
	// HEADERFLAGS(FL_FILE | FL_FUNC | FL_LINE);
	// LOGC(BLUE) << "ld" << 5.45f << LEND;
	// //LOG.header_len = 10;
	// std::cout << "pfnwe";

	// Dog a;
	Cat b;
	Cat c;

	// a = Dog();
	b = Cat( c );
	// a.makeSound();
	b.makeSound();
	return (0);
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	...
// 	return 0;
// }
