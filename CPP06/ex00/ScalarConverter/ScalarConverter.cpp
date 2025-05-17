#include "ScalarConverter.hpp"

static bool isFloatPseudoLiteral( const std::string& s ) {
	return s == "-inff" || s == "+inff" || s == "nanf";
}

static bool isDoublePseudoLiteral( const std::string& s ) {
	return s == "-inf" || s == "+inf" || s == "nan";
}

void ScalarConverter::convert( std::string literal ) {
	double	value = 0.0;
	bool	isChar = false;
	bool	isFloat = false;

	if ( literal.length() == 1 && isalpha( literal[ 0 ] ) ) {
		std::ostringstream	ss;
		ss << static_cast< int >( literal[ 0 ] );
		literal = ss.str();
	}

	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
		isChar = true;
		value = static_cast<double>(literal[1]);
	}
	else if (isFloatPseudoLiteral(literal)) {
		isFloat = true;
		if (literal == "nanf")
			value = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff")
			value = std::numeric_limits<float>::infinity();
		else
			value = -std::numeric_limits<float>::infinity();
	}
	else if (isDoublePseudoLiteral(literal)) {
		if (literal == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	}
	else {
		std::istringstream iss(literal);
		if (literal.find('f') != std::string::npos && literal.find('.') != std::string::npos) {
			isFloat = true;
			iss >> value;
		}
		else {
			iss >> value;
		}
		if (iss.fail()) {
			std::cout << "Invalid literal." << std::endl;
			return;
		}
	}

	if (value < 0 || value > 127 || isnan(value) || isinf(value))
		LOGC( INFO ) << "char: " << "Out of range";
	else if (!isprint(static_cast<int>(value)))
		LOGC( INFO ) << "char: " << "Non displayable";
	else
		LOGC( INFO ) << "'" << static_cast<char>(value) << "'";

	if (isnan(value) || isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		LOGC( INFO ) << "int: " << "Out of range";
	else
		LOGC( INFO ) << static_cast<int>(value);

	LOGC( INFO ) << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>(value) << "f";

	LOGC( INFO ) << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>(value);
}
