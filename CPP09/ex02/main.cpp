#include "proto.hpp"

int main (int argc, char **argv) {

	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
		return 1;
	}

	std::vector<int> _vectorData;
	std::list<int> _listData;

	for (int i = 1; i < argc; ++i) {
		int number = std::atoi(argv[i]);
		if (number <= 0) {
			std::cerr << "Error: All arguments must be positive integers." << std::endl;
			return 1;
		}
		long long temp = std::atoll(argv[i]);
		if (temp > INT_MAX) {
			std::cerr << "Error: Integer value out of range." << std::endl;
			return 1;
		}
		_vectorData.push_back(number);
		_listData.push_back(number);
	}
	std::cout << "Before:";
	for (size_t i = 0; i < _vectorData.size(); ++i) {
		std::cout << " " << _vectorData[i];
	}
	std::cout << std::endl;

	PmergeMe sorter;
	sorter.run(_vectorData);
	sorter.run(_listData);

	std::cout << "After:";
	for (size_t i = 0; i < _vectorData.size(); ++i) {
		std::cout << " " << _vectorData[i];
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : "
			  << sorter.getVectorTime() << " us" << std::endl;
	std::cout << "Time to process a range of " << _listData.size() << " elements with std::list   : "
			  << sorter.getListTime() << " us" << std::endl;
	return 0;
}
