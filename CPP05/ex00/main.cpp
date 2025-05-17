#include "Bureaucrat/Bureaucrat.hpp"

int	main() {
	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Grade range check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	LOGC( INFO ) << "Minimum: " << Bureaucrat::minGrade;
	LOGC( INFO ) << "Maximum: " << Bureaucrat::maxGrade  << LEND;

	std::cout << "-------------------------------------------------------------" << LEND;
	LOGC( INFO ) << "Instancation of valid and invalid bureaucrat check.";
	std::cout << "-------------------------------------------------------------" << LEND << LEND;

	for ( int i = 0; i < 10; i++ ) {
		void	*base = NULL;
		unsigned int grade = ( ( unsigned long long )&base >> ( i * 8 ) ) & 0xFF;
		grade = grade % Bureaucrat::minGrade * 2;

		LOGC( INFO ) << "Grade: " << grade << " should work: " << ( grade > Bureaucrat::minGrade || grade < Bureaucrat::maxGrade ? "NO" : "YES" );
		Bureaucrat	test( "name", grade );
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
