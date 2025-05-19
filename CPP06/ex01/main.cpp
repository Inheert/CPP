/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:56 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/19 12:44:09 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer/Serializer.hpp"
#include "utils/Log/Log.hpp"

int	main( void ) {
	Data	d;
	uintptr_t	serialise = Serializer::serialize( &d );

	LOG() << "Original ptr: " << &d;
	LOG() << "Serialise ptr: " << serialise;
	LOG() << "Deserialise uintptr: " << Serializer::deserialize( serialise );
}
