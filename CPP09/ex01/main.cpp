#include "RPN.hpp"

bool isOp(std::string op, int c) {
	return (op.find(c) != std::string::npos);
}

bool parse(std::string line) {
	bool space = false;
	RPN calculator = RPN();
	for (int i = 0 ; line[i]; i++) {

		if (space == true && line[i] == ' ')
			space = false;
		else if (space == false && isOp(OPERATOR, line[i])) {
			switch (line[i]){
				case '+':
					try {calculator.plus();} catch (std::exception &e) {std::cout << ERROR_PROMPT << e.what() << std::endl; return (false);}
					break;
				case '-':
					try {calculator.minus();} catch (std::exception &e) {std::cout << ERROR_PROMPT << e.what() << std::endl; return (false);}
					break;
				case '*':
					try {calculator.multiply();} catch (std::exception &e) {std::cout << ERROR_PROMPT << e.what() << std::endl; return (false);}
					break;
				case '/':
					try {calculator.divide();} catch (std::exception &e) {std::cout << ERROR_PROMPT << e.what() << std::endl; return (false);}
					break;
			}
			space = true;
		}
		else if (space == false && isdigit(line[i])) {
			calculator.addNumber(line[i] - '0');
			space = true;
		}
		else {
			if (line[i] == ' ')
				std::cerr << ERROR_PROMPT << SPACE_ERROR << std::endl;
			else if (isOp(OPERATOR, line[i]))
				std::cerr << ERROR_PROMPT << OP_ERROR << std::endl;
			else if (isdigit(line[i]))
				std::cerr << ERROR_PROMPT << DIGIT_ERROR << std::endl;
			else
				std::cerr << ERROR_PROMPT << line[i] << CHAR_ERROR << std::endl;
			return (false);
		}
	}
	try {calculator.printRes();} catch (std::exception &e) {std::cout << ERROR_PROMPT << e.what() << std::endl; return (false);}
	return (true);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << ERROR_PROMPT << USAGE_ERROR << std::endl;
		return (EXIT_SUCCESS);
	}
	if (!av[1] || !av[1][0]){
		std::cerr << ERROR_PROMPT << EMPTY_LINE_ERROR << std::endl;
		return (EXIT_SUCCESS);
	}
	if (parse(av[1]) == false)
		return (EXIT_SUCCESS);
	
	return (EXIT_SUCCESS);
}