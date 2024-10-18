/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:25:13 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 10:25:47 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
# define Contact_HPP

#include <iostream>
#include <string>

class	Contact {
	public:
		Contact(void);
		std::string	GetFirstname();
		void		SetFirstName(std::string);
		std::string	GetLastname();
		void		SetLastName(std::string);
		std::string	GetNickname();
		void		SetNickname(std::string);
		std::string	GetPhoneNumber();
		void		SetPhoneNumber(std::string);
		std::string	GetDarkestSecret();
		void		SetDarkestSecret(std::string);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
