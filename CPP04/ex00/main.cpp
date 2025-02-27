/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:19 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 14:00:15 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>

// void	log(std::string &msg, ...) {
// 	std::cout << msg;
// }

#include "utils/Log/Log.hpp"
#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongCat/WrongCat.hpp"

int main()
{
	LOGFLAGS( FL_FILE | FL_LINE | FL_FUNC );
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	WrongCat	badCat;
	Cat	a;
	Cat	b = Cat();
	Dog	c;
	Dog	d = Dog();


	a = b;
	d = c;
	c = Dog( d );
	badCat = WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	badCat.makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}
