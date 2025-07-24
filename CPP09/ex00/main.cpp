#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << ERROR_FLAG<< USAGE_ERROR << std::endl;
		return (EXIT_SUCCESS);
	}
	if (parse(av[1]) == false) {
		return (EXIT_SUCCESS);
	}

	return (EXIT_SUCCESS);
}

// int main() {
// 	std::cout << BISEXTILE(2200) << std::endl;
// 	std::cout << BISEXTILE(1976) << std::endl;
// 	std::cout << BISEXTILE(1950) << std::endl;
// 	std::cout << BISEXTILE(1900) << std::endl;
// 	std::cout << BISEXTILE(2000) << std::endl;
// 	std::cout << BISEXTILE(1967) << std::endl;
// 	std::cout << BISEXTILE(2015) << std::endl;
// }