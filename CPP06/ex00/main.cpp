#include "ScalarConverter/ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	LOGFLAGS( FL_FUNC | FL_LINE );
	std::string	tmp = argv[ 1 ];

	ScalarConverter::convert(tmp);
	return 0;
}

