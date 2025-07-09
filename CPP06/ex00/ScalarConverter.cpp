#include "ScalarConverter.hpp"

/* ===================== Utils ===================== */

struct ValueTab {
	int i;
	float f;
	double d;
	bool bi;
	bool bf;
	bool bd;
	bool nan; // Not a Number, needed to custom prompt
};

void	resultPrinter(ValueTab valueTab) {
	// Char's Prompt
	std::cout << "char: ";
	if (valueTab.bi == false)
		std::cout << "impossible";
	else if (valueTab.i >= 32 && valueTab.i <= 126)
		std::cout << "'" << static_cast<char>(valueTab.i) << "'";
	else 
		std::cout << "Non displayable";
	std::cout << std::endl;

	// Int's Prompts 
	std::cout << "int: ";
	if (valueTab.bi == false)
		std::cout << "impossible";
	else 
		std::cout << valueTab.i;
	std::cout << std::endl;

	// Float's Prompts 
	std::cout << "float: ";
	if (valueTab.bf == false && valueTab.nan == false)
		std::cout << "impossible";
	else if (valueTab.nan == true)
		std::cout << "nan" << 'f';
	else if (valueTab.f == std::floor(valueTab.f))
		std::cout << valueTab.f << ".0" << 'f';
	else
		std::cout << valueTab.f << 'f';
	std::cout << std::endl;

	// Double's Prompts 
	std::cout << "double: ";
	if (valueTab.bd == false && valueTab.nan == false)
		std::cout << "impossible";
	else if (valueTab.nan == true)
		std::cout << "nan";
	else if (valueTab.d == std::floor(valueTab.d))
		std::cout << valueTab.d << ".0";
	else
		std::cout << valueTab.d;
	std::cout << std::endl;
}

/* ================= Canonical Form ================= */

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << "ScalarConverter Copy Constructor" << std::endl;
	*this = other;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << "ScalarConverter Copy Assignement" << std::endl;
	(void)other;
	return (*this);
}

/* ================= Member FUnction ================= */

void ScalarConverter::convert(const std::string str) {
	ValueTab valueTab;
	std::stringstream tmp(str);
	std::stringstream tmpb(str);
	std::stringstream tmpt(str);

	tmp >> valueTab.d;
	tmpb >> valueTab.f;
	tmpt >> valueTab.i;
	valueTab.bi = false;
	valueTab.bf = false;
	valueTab.bd = false;

	if (str == "nan") {
		valueTab.nan = true;
	 }
	else if (isdigit(str[0]) == true) {
		valueTab.bi = true;
		valueTab.bf = true;
		valueTab.bd = true; }
	resultPrinter(valueTab);
}

