#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << ERROR_PROMPT<< USAGE_ERROR << std::endl;
		return (EXIT_SUCCESS);
	}
	if (parse(av[1]) == false) {
		return (EXIT_SUCCESS);
	}

	return (EXIT_SUCCESS);
}
