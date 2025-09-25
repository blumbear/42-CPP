#include "BitcoinExchange.hpp"

void	printDb(std::map<std::string, double> DB) {
	std::map<std::string, double>::iterator it;
	for (it = DB.begin(); it != DB.end(); it++) {
		std::cout << it->first << "," << it->second << std::endl;
	}
}

bool formatCheck(std::string date) {
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; date[i]; i++) {
		if (isdigit(date[i]) == false && i != 4 && i != 7){
			return (false);
		if (i > 10) {
			return (false);}
		}
	}
	return (true);
}

std::map<std::string, double> parseDb() {
	std::ifstream	file(DATA_BASE);
	std::string	line;
	std::map<std::string, double> DB;

	if (file.is_open() == false)
		throw false;
	
	getline(file, line); // skip header

	while (getline(file, line)) {

		size_t sepPos = line.find(DATA_DELIMITER);

		if (sepPos != std::string::npos) {
			std::string date = line.substr(0, sepPos);
			date.resize(10);
			std::stringstream ss(line.substr(sepPos + 1));

			float value;
			if (!(ss >> value)) {
				std::cerr << ERROR_PROMPT << INPUT_ERROR << line << std::endl;
				throw false;
			}
			if (formatCheck(date) == false) {
				std::cout << date << std::endl;
				throw false;}
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
			if (month > 12 || month < 1 || year < 2009 || (year == 2009 && month == 1 && day < 2) || day > 31 || day < 0)
				throw false;
			DB.insert(std::pair<std::string, double>(date, value));
		}
	}
	return (DB);
}

double findDate(std::map<std::string, double> DB, std::string date) {
	std::map<std::string, double>::iterator it = DB.find(date);
	if (it != DB.end()){
		return (it->second);}

	bool test = false;
	it = DB.begin();
	while (it != DB.end()) {
		if (it->first.compare(0, 4, date, 0, 4) == 0) {
			test = true;
			break;
		}
		it++;
	}

	if (test == true) {
		while ((atoi(it->first.substr(5,2).c_str()) < atoi(date.substr(5,2).c_str())) && it->first.compare(0, 4, date, 0, 4) == 0) {
			it++;
		}
	}

	if (test == true) {
		while ((atoi(it->first.substr(8,2).c_str()) < atoi(date.substr(8,2).c_str())) && it->first.compare(5, 2, date, 5, 2) == 0)
			it++;
		it--;
		return (it->second);
	}
	return (0);
}

void printLineResult(std::string date, float value, std::map<std::string, double> DB) {
	int year = 0;
	int month = 0;
	int day = 0;
	size_t sepPos = date.find(DATE_DELIMITER);
	if (formatCheck(date) == false)
		throw false;
	if (sepPos == std::string::npos)
		throw false;
	year = atoi(date.substr(0, sepPos).c_str());
	day = date.find_last_of(DATE_DELIMITER);
	month = atoi(date.substr(sepPos + 1, day).c_str());
	sepPos = day;
	day = atoi(date.substr(sepPos + 1).c_str());
	if (day < 1 || day > 31 || (month == 2 && day > 29) || (!BISEXTILE(year) && month == 2 && day > 28) || month > 12 || month < 1 || year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw false;
	std::cout << date << " => " << value << " = " << findDate(DB, date) * value << std::endl;
	return ;
}

bool parse(char *_file) {
	std::map<std::string, double> DB;
	std::ifstream	file(_file);
	std::string		line;

	try{
		DB = parseDb();
	}
	catch (bool e) {
		std::cerr << ERROR_PROMPT << DBPARSE_ERROR << std::endl;
		return (false);
	}
	if (file.is_open() == false) {
		std::cerr << ERROR_PROMPT << FILE_ERROR << std::endl;
		return (false);
	}

	getline(file, line); // skip header

	std::cout  << std::fixed << std::setprecision(2);
	while (getline(file, line)) {
		size_t sepPos = line.find(INPUT_DELIMITER);
		if (sepPos != std::string::npos) {
			std::string date = line.substr(0, sepPos);
			date.resize(10);
			std::stringstream ss(line.substr(sepPos + 2));
			float value;
			if (!(ss >> value))
				std::cout << ERROR_PROMPT << INPUT_ERROR << line << std::endl;
			else if (value < 0)
				std::cout << ERROR_PROMPT << VALUETOOLOW_ERROR << std::endl;
			else if (value > 1000)
				std::cout << ERROR_PROMPT << VALUETOOHIGHT_ERROR << std::endl;
			else {
				try { printLineResult(date, value, DB); }
				catch(bool e) {
					std::cout << ERROR_PROMPT <<  INPUT_ERROR << line << std::endl;
				}
			}
		}
		else {
			std::cout << ERROR_PROMPT << INPUT_ERROR << line << std::endl;
		}
	}
	return (true);
}