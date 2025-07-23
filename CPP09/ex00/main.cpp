#include "BitcoinExchange.hpp"

void	printDb(std::map<std::string, float> DB) {
	std::map<std::string, float>::iterator it;
	for (it = DB.begin(); it != DB.end(); it++) {
		std::cout << it->first << "," << it->second << std::endl;
	}
}

std::map<std::string, float> parseDb() {
	std::ifstream	file(DATA_BASE);
	std::string	line;
	std::map<std::string, float> DB;

	if (file.is_open() == false)
		throw false;
	
	getline(file, line); // skip header

	while (getline(file, line)) {

		size_t sepPos = line.find(DATA_DELIMITER);

		if (sepPos != std::string::npos) {

			std::string date = line.substr(0, sepPos);
			std::stringstream ss(line.substr(sepPos + 1));

			float value;
			if (!(ss >> value)) {
				std::cerr << ERROR_FLAG << INPUT_ERROR << line << std::endl;
				throw false;
			}

			int year = 0;
			int month = 0;
			int day = 0;
			sepPos = date.find(DATE_DELIMITER);
			year = atoi(date.substr(0, sepPos).c_str());
			day = date.find_last_of(DATE_DELIMITER);
			month = atoi(date.substr(sepPos + 1, day).c_str());
			sepPos = day;
			day = 0;
			day = atoi(date.substr(sepPos + 1).c_str());
			if (month > 12 || month < 1 || (year < 2009 && month == 1 && day < 3) || day > 31 || day < 0)
				throw false;
			DB.insert(std::pair<std::string, int>(date, value));
		}
	}
	return (DB);
}

float findDate(std::map<std::string, float> DB, std::string date) {
	//cherche une date et renvoi la valeur du btc à cette dernière
}

void printLineResult(std::string date, float value, std::map<std::string, float> DB) {
	int year = 0;
	int month = 0;
	int day = 0;
	size_t sepPos = date.find(DATA_DELIMITER);

	if (sepPos == std::string::npos)
		throw false;
	// faire une fonction qui vérifie le format de la date et l'implémenter dans le parse de la data
	year = atoi(date.substr(0, sepPos).c_str());
	day = date.find_last_of(DATE_DELIMITER);
	month = atoi(date.substr(sepPos + 1, day).c_str());
	sepPos = day;
	day = atoi(date.substr(sepPos + 1).c_str());
	if (day < 1 || day > 31 || (BISEXTILE(year) && month == 2 && day > 29) || (!BISEXTILE(year)) && month == 2 && day > 28)
		throw false;
	std::cout << date << " => " << value << " = " << findDate(DB, date) * value;
}

bool parse(char *_file) {
	std::map<std::string, float> DB;
	std::ifstream	file(_file);
	std::string		line;

	try{
		DB = parseDb();
	}
	catch (bool e) {
		std::cout << ERROR_FLAG << DBPARSE_ERROR << std::endl;
		return (false);
	}
	if (file.is_open() == false) {
		std::cout << ERROR_FLAG << FILE_ERROR << std::endl;
		return (false);
	}

	getline(file, line); // skip header

	while (getline(file, line)) {
		size_t sepPos = line.find(INPUT_DELIMITER);
		if (sepPos != std::string::npos) {
			std::string date = line.substr(0, sepPos);
			std::stringstream ss(line.substr(sepPos + 1));

			float value;
			if (!(ss >> value))
				std::cerr << ERROR_FLAG << INPUT_ERROR << line << std::endl;
			else if (value < 0)
				std::cout << ERROR_FLAG << VALUETOOLOW_ERROR << std::endl;
			else if (value > 1000)
				std::cout << ERROR_FLAG << VALUETOOHIGHT_ERROR << std::endl;
			else {
				try { printLineResult(date, value, DB); }
				catch(bool e) {
					std::cout << ERROR_FLAG << INPUT_ERROR << line << std::endl;
				}
			}
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

// int main() {
// 	std::cout << BISEXTILE(2200) << std::endl;
// 	std::cout << BISEXTILE(1976) << std::endl;
// 	std::cout << BISEXTILE(1950) << std::endl;
// 	std::cout << BISEXTILE(1900) << std::endl;
// 	std::cout << BISEXTILE(2000) << std::endl;
// 	std::cout << BISEXTILE(1967) << std::endl;
// 	std::cout << BISEXTILE(2015) << std::endl;
// }