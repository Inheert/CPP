/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:24 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 10:45:07 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "phonebook.h"

class	PhoneBook {
	public:
		PhoneBook();
		void	Add(Contact);
		void	Display(void);
		void	Search(int index);
	private:
		Contact	contacts[8];
};

#endif
