/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:14:37 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 15:54:38 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phonebook.h"

int	GetForm(PhoneBook *phoneBook) {
	Contact		contact;
	std::string	value;
	
	std::cout << "\nYou are going to create a new contact, please follow the next instructions:\n";
	std::cout << "First name: ";
	std::cin >> value;
	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	contact.SetFirstName(value);
	
	std::cout << "Last name: ";
	std::cin >> value;
	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	contact.SetLastName(value);

	std::cout << "Nickname: ";
	std::cin >> value;
	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	contact.SetNickname(value);

	std::cout << "Phone number: ";
	std::cin >> value;
	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	contact.SetPhoneNumber(value);
	
	std::cout << "Darkest secret: ";
	std::cin >> value;
	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	contact.SetDarkestSecret(value);
	phoneBook->Add(contact);
	std::cout << "\n";
	return (0);
}

bool isNum(const std::string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int	GetSearch(PhoneBook *phoneBook) {
	std::string	value;
	int			index;

	phoneBook->Display();
	std::cout << "\nPlease enter the index of the contact whose details you wish to view: ";
	std::cin >> value;
	if (std::cin.eof()) {
		std::cout << "\n";
		return (1);
	}
	if (!isNum(value)) {
		std::cout << "\n\033[0;31mError, only number is accepted.\033[0m\n\n";
		return (0);
	}
	std::stringstream ss(value);
	ss >> index;
	phoneBook->Search(index);
	return (0);
}

int	main(void) {
	PhoneBook	phoneBook;
	std::string	value;

	while (1)
	{
		std::cout << "Please enter a command (ADD, SEARCH or EXIT).\n";
		std::cin >> value;
		if (std::cin.eof())
			return (1);
		if (value.compare("ADD") == 0) {
			if (GetForm(&phoneBook))
				return (1);
		}
		else if (value.compare("SEARCH") == 0) {
			if (GetSearch(&phoneBook))
				return (1);
		}
		else if (value.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "\033[0;31m Please enter a valid command.\033[0m\n\n";
	}
	return (0);
}
