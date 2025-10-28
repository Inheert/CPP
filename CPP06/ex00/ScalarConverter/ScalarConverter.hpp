/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:30:13 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/28 09:01:27 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

#include "../utils/Log/Log.hpp"

class ScalarConverter {
	private:
		ScalarConverter();

	public:
		static void convert( std::string rep );
};
