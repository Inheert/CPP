/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:24 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/19 00:04:50 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "phonebook.h"

class	PhoneBook {
	public:
		PhoneBook();
		void		Add(Contact);
		void		Display(void);
		void		Search(int);
	private:
		Contact		contacts[8];
		int			oldestContactIndex;
};

#endif
