/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:26 by tclaereb          #+#    #+#             */
/*   Updated: 2025/05/17 11:29:46 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

class Serializer {
	private:
		Serializer( void );
		Serializer( const Serializer &other );
		Serializer	&operator=( const Serializer &other );
		~Serializer( void );

	public:
		uintptr_t	serialize( void *ptr );
		void		*deserialize( uintptr_t raw );
};
