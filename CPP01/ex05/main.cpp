/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:37:47 by Théo              #+#    #+#             */
/*   Updated: 2024/10/20 14:54:06 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl/Harl.hpp"

int	main( void ) {
	Harl	harl = Harl();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("WARNING");
	return (0);
}