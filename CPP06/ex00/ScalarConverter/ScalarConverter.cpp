/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:25:38 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/29 12:48:52 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isFloatPseudoLiteral( const std::string& s ) {
	return ( s == "-inff" || s == "+inff" || s == "nanf" || s == "inff" );
}

static bool isDoublePseudoLiteral( const std::string& s ) {
	return ( s == "-inf" || s == "+inf" || s == "nan" || s == "inf" );
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
		LOGC( CRITICAL ) << "float: Impossible";
	else
		LOGC( INFO ) << "double: " << std::fixed << std::setprecision( 5 ) << d;
}

static bool doesItOverflow( const std::string& s, const std::string type ) {
	std::stringstream	ss;
	ss << s;

	if ( type == "char" ) {
		int	c;
		ss >> c;
		return ( c <= 0 || c >= 127 );
	} else if ( type == "int" ) {
		int	i;
		ss >> i;
	} else if ( type == "float" ) {
		float	f;
		ss >> f;
	} else if ( type == "double" ) {
		double	d;
		ss >> d;
	}
	return ( ss.fail() );
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

	displayChar( static_cast< char >( i ), !ss.fail() && !doesItOverflow( s, "char" ) );
	displayInt( i, !ss.fail() );
	displayFloat( static_cast< float >( i ), !ss.fail() );
	displayDouble( static_cast< double >( i ), !ss.fail() );

}

static void fromFloat( const std::string& s ) {
	std::stringstream	ss;
	float				f;

	if ( isFloatPseudoLiteral( s ) ) {
		if ( s == "nanf" )
			f = std::numeric_limits< float >::quiet_NaN();
		else if ( s == "+inff" || s == "inff" )
			f = std::numeric_limits< float >::infinity();
		else
			f = -std::numeric_limits< float >::infinity();
	} else {
		ss << s;
		ss >> f;
	}

	if ( isFloatPseudoLiteral( s ) ) {
		displayChar( static_cast< char >( f ), false );
		displayInt( static_cast< int >( f ), false );
		displayFloat( static_cast< double >( f ), true );
		displayDouble( static_cast< double >( f ), true );
	} else {
		displayChar( static_cast< char >( f ), !ss.fail() && !doesItOverflow( s, "char" ) );
		displayInt( static_cast< int >( f ), !ss.fail() && doesItOverflow( s, "int" ) );
		displayFloat( static_cast< double >( f ), !ss.fail() );
		displayDouble( static_cast< double >( f ), !ss.fail() );
	}
}

static void fromDouble( const std::string& s ) {
	std::stringstream	ss;
	double				d;

	if ( isDoublePseudoLiteral( s ) ) {
		if ( s == "nan" )
			d = std::numeric_limits< double >::quiet_NaN();
		else if ( s == "+inf" || s == "inf" )
			d = std::numeric_limits< double >::infinity();
		else
			d = -std::numeric_limits< double >::infinity();
	} else {
		ss << s;
		ss >> d;
	}

	if ( isDoublePseudoLiteral( s ) ) {
		displayChar( static_cast< char >( d ), false );
		displayInt( static_cast< int >( d ), false );
		displayFloat( static_cast< double >( d ), true );
	} else {
		displayChar( static_cast< char >( d ), !ss.fail() && !doesItOverflow( s, "char" ) );
		displayInt( static_cast< int >( d ), !ss.fail() && !doesItOverflow( s, "int" ) );
		displayFloat( static_cast< double >( d ), !ss.fail() && !doesItOverflow( s, "float" ) );
	}
	displayDouble( d, !ss.fail() );
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
