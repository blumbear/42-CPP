#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Usage: ./convert \"value\"" << std::endl;
		return (EXIT_SUCCESS);
	}
	ScalarConverter::convert(static_cast<std::string>(av[1]));
	return (EXIT_SUCCESS);
}