/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:14:37 by tclaereb          #+#    #+#             */
/*   Updated: 2024/10/18 10:28:11 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phonebook.h"

int	main(void)
{
	Contact	contact;

	contact.SetDarkestSecret("very secret darkest that is secret and dark");
	std::cout << contact.GetDarkestSecret() + "\n";
	return (0);
}
