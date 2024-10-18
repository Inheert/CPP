/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:25:11 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 13:54:28 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

std::string	Contact::GetFirstname(void) {
	return (this->_firstName);
}

void	Contact::SetFirstName(std::string firstName) {
	this->_firstName =firstName;
}

std::string	Contact::GetLastname(void) {
	return (this->_lastName);
}

void	Contact::SetLastName(std::string lastName) {
	this->_lastName =lastName;
}

std::string	Contact::GetNickname(void) {
	return (this->_nickname);
}

void	Contact::SetNickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string	Contact::GetPhoneNumber(void) {
	return (this->_phoneNumber);
}

void	Contact::SetPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::GetDarkestSecret(void) {
	return (this->_darkestSecret);
}

void	Contact::SetDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
