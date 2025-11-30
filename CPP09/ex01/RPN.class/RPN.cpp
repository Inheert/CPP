/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:20:51 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/30 20:00:14 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN( const RPN &other ) {
	this->_stack = other._stack;
}

RPN	&RPN::operator=( const RPN &other ) {
	if ( this == &other ) {
		return ( *this );
	}

	this->_stack = other._stack;
	return ( *this );
}

RPN::~RPN( void ) {}

static bool	isCharOperator( const char &c ) {
	if ( c == '+' || c == '-' || c == '/' || c == '*' )
		return ( true );
	return ( false );
}

static bool	isStringValid( const std::string &input ) {
	for ( size_t i = 0; i < input.length(); i++ ) {
		if ( !std::isdigit( input[ i ] ) && input[ i ] != ' ' && input[ i ] != '\t' && !isCharOperator( input[ i ] ) )
			return ( false );
	}
	return ( true );
}

double	RPN::execute( const std::string &input ) {
	if ( !isStringValid( input ) )
		throw ( InvalidInputException() );

	for ( size_t i = 0; i < input.length(); i++ ) {
		char c = input[ i ];

		if ( c == ' ' || c == '\t' )
			continue ;

		if ( std::isdigit( c ) ) {
			this->_stack.push( c - '0' );
		} else if ( isCharOperator( c ) ) {
			if ( this->_stack.size() < 2 )
				throw ( TooFewNumberException() );

			int result = 0;
			int b = this->_stack.top();
			this->_stack.pop();
			int a = this->_stack.top();
			this->_stack.pop();

			switch ( c ) {
				case '+':
					result = a + b;
					break ;
				case '-':
					result = a - b;
					break ;
				case '*':
					result = a * b;
					break ;
				case '/':
					if ( b == 0 )
						throw ( DivisionByZeroException() );
					result = a / b;
					break ;
			}
			this->_stack.push( result );
		}
	}
	if ( this->_stack.size() != 1 )
		throw ( MissingOperatorException() );

	double finalValue = this->_stack.top();
	this->_stack.pop();
	return ( finalValue );
}

const char	*RPN::InvalidInputException::what() const throw() {
	return ( "Error: input contain invalid character(s)." );
}

const char	*RPN::TooFewNumberException::what() const throw() {
	return ( "Error: needs at leat 2 numbers." );
}

const char	*RPN::DivisionByZeroException::what() const throw() {
	return ( "Error: division by zero not possible." );
}

const char	*RPN::MissingOperatorException::what() const throw() {
	return ( "Error: invalid numbers or operators." );
}
