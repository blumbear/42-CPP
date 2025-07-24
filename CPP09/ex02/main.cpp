#include "PmergeMe.hpp"

void Data::parse(char **array) {
	for (int i = 0; array[i]; i++) {
		for (int j = 0; array[i][j]; j++) {
			if (!isdigit(array[i][j])) {
				std::cerr << ERROR_PROMPT << ARG_ERROR << std::endl;
				throw false;
			}
		}
		_vector.push_back(atoi(array[i]));
		_list.push_back(atoi(array[i]));
	}
}

int main(int ac, char **av) {
	Data data=Data();
	if (ac < 2) {
		std::cerr << ERROR_PROMPT << USAGE_ERROR << std::endl;
	}
	try {
		data.parse(++av);
		data.printVector();
		data.printList();
	} catch (bool e) {
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}