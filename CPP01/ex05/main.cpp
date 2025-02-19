#include "Harl.h"
#include "Harl.hpp"

int main(void)
{
	Harl harl = Harl();
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("TEST");
}