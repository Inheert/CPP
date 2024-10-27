/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:21 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/27 08:37:10 by tclaereb         ###   ########.fr       */
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

	std::cout << std::endl << "     Index|First name| Last name|  Nickname|     Phone|    Secret" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
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
			std::cout << std::setfill(' ') << std::setw(11) << value << "" << std::endl;
		else
			std::cout << value.substr(0, 9) + "." << "" << std::endl;
	}
}

void	PhoneBook::Search(int index) {
	if (index < 0 || index > 7 || this->contacts[index].GetFirstname().length() == 0) {
		std::cout << std::endl << "\033[0;31mNo contact found with the index: '";
		std::cout << index;
		std::cout << "', the contact may not exist or the index is not in a valid range (0 - 7).\033[0m" << std::endl << std::endl;
		return ;
	}
	std::cout << std::endl << "Contact details (index: " << index << ")" << std::endl;
	std::cout << "First name: " + this->contacts[index].GetFirstname() + "" << std::endl;
	std::cout << "Last name: " + this->contacts[index].GetLastname() + "" << std::endl;
	std::cout << "Nickname: " + this->contacts[index].GetNickname() + "" << std::endl;
	std::cout << "Phone number: " + this->contacts[index].GetPhoneNumber() + "" << std::endl;
	std::cout << "Darkest secret: " + this->contacts[index].GetDarkestSecret() << std::endl << std::endl;
}


