/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:56 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/28 07:34:00 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer/Serializer.hpp"
#include "utils/Log/Log.hpp"

int	main( void ) {
	Data	d;

	d.ptr = new std::string();

	uintptr_t	serialise = Serializer::serialize( &d );
	Data		*ptr = Serializer::deserialize( serialise );

	LOG() << "Original ptr: " << &d;
	LOG() << "Serialise ptr: " << serialise;
	LOG() << "Deserialise uintptr: " << ptr;

	delete ptr->ptr;
}
