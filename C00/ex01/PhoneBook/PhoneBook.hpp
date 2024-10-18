/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:24 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 15:01:22 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
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
