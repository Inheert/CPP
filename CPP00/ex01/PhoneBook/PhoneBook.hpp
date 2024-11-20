/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:24 by tclaereb          #+#    #+#             */
/*   Updated: 2024/11/18 08:42:29 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "../Contact/Contact.hpp"

class	PhoneBook {
	private:
		Contact		contacts[8];
		int			oldestContactIndex;

	public:
		PhoneBook();
		void		Add(Contact);
		void		Display(void);
		void		Search(int);
};
