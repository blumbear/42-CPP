#include "PmergeMe.hpp"

int main(int ac, char **av) {
	MergeInsertSort data=MergeInsertSort();
	if (ac < 2) {
		std::cerr << ERROR_PROMPT << USAGE_ERROR << std::endl;
		return (EXIT_SUCCESS);
	}
	try {
		data.parse(++av);
		std::cout << "------ Before Compute ------" << std::endl;
		data.printVector();
		data.printList();
		data.compute();
		std::cout << "------ After Compute ------" << std::endl;
		data.printVector();
		data.printList();

	} catch (bool e) {
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}