/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:38 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/28 07:54:58 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isFloatPseudoLiteral( const std::string& s ) {
	return ( s == "-inff" || s == "+inff" || s == "nanf" );
}

static bool isDoublePseudoLiteral( const std::string& s ) {
	return ( s == "-inf" || s == "+inf" || s == "nan" );
}

static bool isValidLiteral( const std::string &s ) {
	if ( s.empty() )
		return ( false );
	if ( s.size() == 1 )
		return ( true );

	if ( isFloatPseudoLiteral( s ) || isDoublePseudoLiteral( s ) )
		return ( true );

	size_t dotCount = 0;
	for ( size_t i = 0; i < s.size(); i++ ) {
		if ( dotCount > 1 )
			return ( false );
		if ( s[ i ] == '.' ) {
			dotCount++;
			continue ;
		}

		if ( !isdigit( s[ i ] ) ) {
			if ( s[ i ] == 'f' && i == s.size() - 1 )
				continue ;
			else if ( ( s[ i ] == '-' || s[ i ] == '+' ) && i == 0 )
				continue ;
			else
				return ( false );
		}
	}
	return ( true );
}

static void displayChar( const char c, bool isValid ) {
	if ( !isValid )
		LOGC( CRITICAL ) << "char: Impossible";
	else if ( !isprint( c ) )
		LOGC( CRITICAL ) << "char: Non displayable";
	else
		LOGC( INFO ) << "char: '" << c << "'";
}

static void displayInt( const int i, bool isValid ) {
	if ( !isValid )
		LOGC( CRITICAL ) << "int: Impossible";
	else
		LOGC( INFO ) << "int: " << i;
}

static void displayFloat( const float f, bool isValid ) {
	if ( !isValid )
		LOGC( CRITICAL ) << "float: Impossible";
	else
		LOGC( INFO ) << "float: " << std::fixed << std::setprecision( 5 ) << f << "f";
}

static void displayDouble( const double d, bool isValid ) {
	if ( !isValid )
		LOGC( CRITICAL ) << "double: Impossible";
	else
		LOGC( INFO ) << "double: " << std::fixed << std::setprecision( 5 ) << d;
}

static void fromChar( const std::string& s ) {
	char	c = s[ 0 ];

	displayChar( c, true );
	displayInt( static_cast< int >( c ), true );
	displayFloat( static_cast< float >( c ), true );
	displayDouble( static_cast< double >( c ), true );
}

static void fromInt( const std::string& s ) {
	std::stringstream	ss;
	int					i;

	ss << s;
	ss >> i;

	displayChar( static_cast< char >( i ), ( i >= 0 && i <= 127 ) );
	displayInt( i, true );
	displayFloat( static_cast< float >( i ), true );
	displayDouble( static_cast< double >( i ), true );
}

static void fromFloat( const std::string& s ) {
	std::stringstream	ss;
	float				f;

	if ( isFloatPseudoLiteral( s ) ) {
		if ( s == "nanf" )
			f = std::numeric_limits< float >::quiet_NaN();
		else if ( s == "+inff" )
			f = std::numeric_limits< float >::infinity();
		else
			f = -std::numeric_limits< float >::infinity();
	} else {
		ss << s;
		ss >> f;
	}

	displayChar( static_cast< char >( f ), ( !isnan( f ) && f >= 0 && f <= 127 ) );
	displayInt( static_cast< int >( f ), ( !isnan( f ) && f > std::numeric_limits< int >::min() && f < std::numeric_limits< int >::max() ) );
	displayFloat( f, true );
	displayDouble( static_cast< double >( f ), true );
}

static void fromDouble( const std::string& s ) {
	std::stringstream	ss;
	double				d;

	if ( isDoublePseudoLiteral( s ) ) {
		if ( s == "nan" )
			d = std::numeric_limits< double >::quiet_NaN();
		else if ( s == "+inf" )
			d = std::numeric_limits< double >::infinity();
		else
			d = -std::numeric_limits< double >::infinity();
	} else {
		ss << s;
		ss >> d;
	}

	displayChar( static_cast< char >( d ), ( !isnan( d ) && d >= 0 && d <= 127 ) );
	displayInt( static_cast< int >( d ), ( !isnan( d ) && d > std::numeric_limits< int >::min() && d < std::numeric_limits< int >::max() ) );
	if ( isDoublePseudoLiteral( s ) )
		displayFloat( static_cast< double >( d ), true );
	else
		displayFloat( static_cast< double >( d ), ( d > std::numeric_limits< float >::min() && d < std::numeric_limits< float >::max() ) );
	displayDouble( d, true );
}

void ScalarConverter::convert( std::string literal ) {
	if ( !isValidLiteral( literal ) ) {
		return ( displayChar( 0, false ), displayInt( 0, false ), displayFloat( 0, false ), displayDouble( 0, false ) );
	}

	if ( isFloatPseudoLiteral( literal ) )
		return ( fromFloat( literal ) );
	else if ( isDoublePseudoLiteral( literal ) )
		return ( fromDouble( literal ) );

	if ( literal.length() == 1 && isalpha( literal[ 0 ] ) )
		fromChar( literal );
	else if ( literal[ literal.length() - 1 ] == 'f' )
		fromFloat( literal );
	else if ( literal.find( '.' ) != std::string::npos )
		fromDouble( literal );
	else
		fromInt( literal );
}
