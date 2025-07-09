#include "ScalarConverter.hpp"

int main(int ac, char **av) {

	ScalarConverter scalarConverter=ScalarConverter();

	if (ac != 2) {
		std::cout << "Error: Usage: ./convert \"value\"" << std::endl;
		return (EXIT_SUCCESS);
	}
	scalarConverter.convert(static_cast<std::string>(av[1]));
	return (EXIT_SUCCESS);
}