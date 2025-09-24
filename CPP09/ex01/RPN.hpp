#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <exception>

#define OPERATOR "+-/*"

#define ERROR_PROMPT "Error: "

#define USAGE_ERROR "Usage: ./RPN <operation in RPN>."
#define CHAR_ERROR " is not an operator or a number."
#define DIGIT_ERROR "Needed a space between two number."
#define OP_ERROR "Needed a space between two operator."
#define SPACE_ERROR "Too many spaces between value or operator, or space before the first number."
#define STACK_ERROR "Not Enough Value in the stack to use the operator."
#define EMPTY_LINE_ERROR "The line is empty."
#define DIVIDE_0_ERROR "Zero cant be divided or cant divide."
#define TOO_MANY_VALUES "Too many values left in stack."

class RPN {
	private :
		std::stack<int>	_stack;
		size_t	_stackSize;
	
	public :

/* ================ Exception Handler ================ */

		class NotEnoughValueInStack: public std::exception {public :const char* what() const throw();};
		class DivideBy0: public std::exception {public :const char* what() const throw();};
		class TooManyValueInStack: public std::exception {public :const char* what() const throw();};

/* ================= Canonical Form ================= */

		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN &operator=(const RPN &other);

/* ================= Member Function ================= */

		void addNumber(const int n);
		void plus();
		void minus();
		void multiply();
		void divide();
		void printRes();
};