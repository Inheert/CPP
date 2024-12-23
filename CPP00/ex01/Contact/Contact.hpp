/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:25:13 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/26 15:36:25 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Contact {
	public:
		Contact(void);
		std::string	GetFirstname(void);
		void		SetFirstName(std::string);
		std::string	GetLastname(void);
		void		SetLastName(std::string);
		std::string	GetNickname(void);
		void		SetNickname(std::string);
		std::string	GetPhoneNumber(void);
		void		SetPhoneNumber(std::string);
		std::string	GetDarkestSecret(void);
		void		SetDarkestSecret(std::string);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};
