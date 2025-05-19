/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:49 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/19 12:38:30 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize( Data *ptr ) {
	return ( reinterpret_cast< uintptr_t >( ptr ) );
}

Data	*Serializer::deserialize( uintptr_t raw ) {
	return ( reinterpret_cast< Data * >( raw ) );
}
