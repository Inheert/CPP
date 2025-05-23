/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/19 12:41:51 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/Data.hpp"

class Serializer {
	private:
		Serializer( void );
		Serializer( const Serializer &other );
		Serializer	&operator=( const Serializer &other );
		~Serializer( void );

	public:
		static uintptr_t	serialize( Data *ptr );
		static Data		*deserialize( uintptr_t raw );
};
