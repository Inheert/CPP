/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 16:29:36 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : oldestContactIndex(0) {}

void	PhoneBook::Add(Contact newContact) {
	this->contacts[oldestContactIndex] = newContact;
	this->oldestContactIndex = (this->oldestContactIndex + 1) % 8;
}

void	PhoneBook::Display(void) {
	std::string	value;

	std::cout << "\n     Index|First name| Last name|  Nickname|     Phone|    Secret\n";
	std::cout << "-----------------------------------------------------------------\n";
	for (int i = 0; i < 8; i++) {
		if (this->contacts[i].GetFirstname() == "")
			continue ;
		std::cout << "         " << i << "|";
		value = this->contacts[i].GetFirstname();
		
		if (value.length() <= 10)
			std::cout << std::setfill(' ') << std::setw(11) << value + "|";
		else
			std::cout << value.substr(0, 9) + ".|";
		
		value = this->contacts[i].GetLastname();
		if (value.length() <= 10)
			std::cout << std::setfill(' ') << std::setw(11) << value + "|";
		else
			std::cout << value.substr(0, 9) + ".|";
		
		value = this->contacts[i].GetNickname();
		if (value.length() <= 10)
			std::cout << std::setfill(' ') << std::setw(11) << value + "|";
		else
			std::cout << value.substr(0, 9) + ".|";
		
		value = this->contacts[i].GetPhoneNumber();
		if (value.length() <= 10)
			std::cout << std::setfill(' ') << std::setw(11) << value + "|";
		else
			std::cout << value.substr(0, 9) + ".|";
		
		value = this->contacts[i].GetDarkestSecret();
		if (value.length() <= 10)
			std::cout << std::setfill(' ') << std::setw(11) << value << "\n";
		else
			std::cout << value.substr(0, 9) + "." << "\n";
	}
}

void	PhoneBook::Search(int index) {
	if (index < 0 || index > 7 || this->contacts[index].GetFirstname().length() == 0) {
		std::cout << "\n\033[0;31mNo contact found with the index: '";
		std::cout << index;
		std::cout << "', the contact may not exist or the index is not in a valid range (0 - 7).\033[0m\n\n";
		return ;
	}
	std::cout << "\nContact details (index: " << index << ")\n";
	std::cout << "First name: " + this->contacts[index].GetFirstname() + "\n";
	std::cout << "Last name: " + this->contacts[index].GetLastname() + "\n";
	std::cout << "Nickname: " + this->contacts[index].GetNickname() + "\n";
	std::cout << "Phone number: " + this->contacts[index].GetPhoneNumber() + "\n";
	std::cout << "Darkest secret: " + this->contacts[index].GetDarkestSecret() + "\n\n";
}


