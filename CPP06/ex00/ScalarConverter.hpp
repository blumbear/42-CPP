#pragma once

#include <string>
#include <iostream>
#include <iomanip> // for fixed and setprecision
#include <sstream> // for stringstream type
#include <cctype> // for isdigit
#include <cmath> // for std::floor

class ScalarConverter {
	private :
	/* ================= Canonical Form ================= */

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		
	public :

	/* ================= Member FUnction ================= */

		static void convert(const std::string str);
};