/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:19:55 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/30 19:57:53 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include "../utils/Log/Log.hpp"

class RPN {
	private:
		std::stack< int >	_stack;

	public:
		RPN( void );
		RPN( const RPN &other );
		RPN	&operator=( const RPN &other );
		~RPN( void );

		double	execute( const std::string &input );

		class InvalidInputException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class TooFewNumberException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class DivisionByZeroException : public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class MissingOperatorException : public std::exception {
			public:
				virtual char const *what() const throw();
		};
};
