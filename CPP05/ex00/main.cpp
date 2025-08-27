#include "Bureaucrat/Bureaucrat.hpp"

#include <cstdlib>

int	main() {
	srand( time( NULL ) );
	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Grade range check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	LOGC( INFO ) << "Minimum: " << Bureaucrat::minGrade;
	LOGC( INFO ) << "Maximum: " << Bureaucrat::maxGrade  << LEND;

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Instancation of valid and invalid bureaucrat check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 10; i++ ) {
		unsigned int grade = rand() % Bureaucrat::minGrade * 2;

		LOGC( INFO ) << "Grade: " << grade << " should work: " << ( grade > Bureaucrat::minGrade || grade < Bureaucrat::maxGrade ? "NO" : "YES" );
		Bureaucrat	test( "customName", grade );
		LOGC( INFO ) << test << LEND;
	}

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Grade incrementation and decrementation check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 2; i++ ) {
		int median = Bureaucrat::minGrade * 0.5;
		Bureaucrat instance( "name", median );

		for ( int j = 0; j < median + 5; j++ ) {
			if ( i % 2 == 0 )
				instance.IncrementGrade();
			else
				instance.DecrementGrade();
		}
	}
}
