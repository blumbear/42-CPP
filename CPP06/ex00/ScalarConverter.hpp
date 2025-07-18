#pragma once

#include <string>
#include <iostream>
#include <sstream> // for stringstream type
#include <cctype> // for isdigit
#include <cmath> // for std::floor

class ScalarConverter {
	private :
		
	public :
	/* ================= Canonical Form ================= */

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);

	/* ================= Member FUnction ================= */

		static void convert(const std::string str);
};