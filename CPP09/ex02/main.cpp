#include "PmergeMe.hpp"

int main(int ac, char **av) {
	MergeInsertSort data=MergeInsertSort();
	if (ac < 2) {
		std::cerr << ERROR_PROMPT << USAGE_ERROR << std::endl;
		return (EXIT_SUCCESS);
	}
	try {
		data.parse(++av);
		std::cout << "Before :";
		data.printVector();
		data.compute();
		std::cout << "After: ";
		data.printVector();
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed<< std::setprecision(5) << data.getvtime() << " us" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << std::fixed<< std::setprecision(5) << data.getdtime() << " us" << std::endl;

	} catch (bool e) {
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}