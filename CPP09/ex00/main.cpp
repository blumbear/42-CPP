#include "BitcoinExchange.hpp"

// std::map<std::string, float> parseDb(std::string) {

// }

bool parse(char *_file) {
	// std::map<std::string, float> DB = parseDb(DATA_BASE);
	std::ifstream	file(_file);
	std::string		line;

	if (file.is_open() == false) {
		std::cout << ERROR_FLAG << FILE_ERROR << std::endl;
		return (false);
	}
	while (getline(file, line)) {
		size_t pos = line.find(DELIMITER);
		if (pos != std::string::npos) {
			std::string date = line.substr(0, pos);

			std::stringstream ss(line.substr(pos + 1));
			float value;
			ss >> value;

			if (value < 0)
				std::cout << ERROR_FLAG << VALUETOOLOW_ERROR << std::endl;
			else if (value > 1000)
				std::cout << ERROR_FLAG << VALUETOOHIGHT_ERROR << std::endl;
			else
				std::cout << date << DELIMITER << value << "l" << std::endl;
		}
		else {
			std::cout << ERROR_FLAG << INPUT_ERROR << line << std::endl;
		}
	}
	return (true);
}

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