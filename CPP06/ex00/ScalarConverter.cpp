#include "ScalarConverter.hpp"

/* ===================== Utils ===================== */

struct ValueTab {
	std::string str;
	int i;
	bool printable;
	float f;
	double d;
	bool pseudoLitt; // -inff, +inff, and nanf, needed to custom prompt
};

void	resultPrinter(ValueTab valueTab) {
	// Char's Prompt
	std::cout << "char: ";
	if (valueTab.i >= 32 && valueTab.i <= 126)
		std::cout << "'" << static_cast<char>(valueTab.i) << "'";
	else if (!(valueTab.i >= 32 && valueTab.i <= 126))
		std::cout << "Non displayable";
	else
		std::cout << "impossible";
	std::cout << std::endl;

	// Int's Prompts 
	std::cout << "int: ";
	if (valueTab.printable == false)
		std::cout << "impossible";
	else 
		std::cout << valueTab.i;
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	// Float's Prompts 
	std::cout << "float: ";
	if (valueTab.printable == false && valueTab.pseudoLitt == false)
		std::cout << "impossible";
	else if (valueTab.pseudoLitt == true)
		std::cout << valueTab.str << 'f';
	else
		std::cout << valueTab.f << 'f';
	std::cout << std::endl;

	// Double's Prompts 
	std::cout << "double: ";
	if (valueTab.printable == false && valueTab.pseudoLitt == false)
		std::cout << "impossible";
	else if (valueTab.pseudoLitt == true)
		std::cout << valueTab.str;
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
	ValueTab tab;

	std::stringstream ss(str);
	ss >> tab.d;

	tab.pseudoLitt = false;
	if (ss.fail()) {
		if (str == "nan" || str == "-inf" || str == "+inf")
			tab.pseudoLitt = true;
	} else
		tab.printable = true;

	tab.str = str;
	tab.i = static_cast<int>(tab.d);
	tab.f = static_cast<float>(tab.d);

	resultPrinter(tab);
}
