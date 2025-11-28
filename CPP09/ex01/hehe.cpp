#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _stackNumber(other._stackNumber), _input(other._input) {

	(void)other;
}

RPN& RPN::operator=(const RPN& other) {

	if (this != &other) {
		_stackNumber = other._stackNumber;
		_input = other._input;
	}
	return *this;
}

int RPN::checkValidCharacters(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isdigit(input[i]) && input[i] != ' ' && input[i] != '\t'
			&& input[i] != '+' && input[i] != '-' && input[i] != '*'
			&& input[i] != '/') {
			return (0);
		}
	}
	return (1);
}

int RPN::calculate(const std::string& input) {

	if (checkValidCharacters(input) == 0)
		throw NonValidCharacterFound();
	std::stack<int> _stackNumber;
	for (size_t i = 0; i < input.length(); i++) {

		char c = input[i];
		if (c == ' ' || c == '\t')
			continue;
		if (std::isdigit(c)) {
			_stackNumber.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (_stackNumber.size() < 2)
				throw InvalidNumberOfOperators();

			int b = _stackNumber.top();
			_stackNumber.pop();
			int a = _stackNumber.top();
			_stackNumber.pop();
			int res = 0;

			switch(c) {
				case '+' :
					res = a + b;
					break ;

				case '-' :
					res = a - b;
					break ;

				case '*' :
					res = a * b;
					break ;

				case '/' :
					if (b == 0)
						throw DivisionByZeroNotPossible();
					res = a / b;
					break ;
			}
			_stackNumber.push(res);
		} else {
			throw NonValidCharacterFound();
		}
		//continuer tant qu'il y a des espaces ou tabs
	}

	if (_stackNumber.size() != 1)
		throw InvalidNumberOfOperators();
	return _stackNumber.top();
}


/*
Checks:
	1) check les caracteres valides ("0123456789 \t*+-/")
	2) check si les 2 premiers sont des chiffres
	3) check si il n'y a que des chiffres et pas des nombres
	4) check si le nombre d'operateur = nombre de chiffres - 1
	5) je vois rien d'autre
*/

const char* RPN::NonValidCharacterFound::what() const throw() {
	return "Non valid character found";
}

const char* RPN::FirstTwoNotDigits::what() const throw() {
	return "First two characters are not digits";
}

const char* RPN::NumberHasbeenFound::what() const throw() {
	return "Number has been found";
}

const char* RPN::InvalidNumberOfOperators::what() const throw() {
	return "Invalid number of operators";
}

const char* RPN::DivisionByZeroNotPossible::what() const throw() {
	return "Division by zero is not possible";
}
