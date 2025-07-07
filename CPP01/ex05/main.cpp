#include "Harl.h"
#include "Harl.hpp"

int main(void)
{
	Harl harl = Harl();
	std::cout << std::endl << "Complain INFO" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "Complain DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "Complain WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "Complain ERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "Complain random" << std::endl;
	harl.complain("TEST");
}