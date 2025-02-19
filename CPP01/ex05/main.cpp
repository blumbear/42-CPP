#include "Harl.h"
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << USAGE_ERROR << '\n';
		return 0;
	}
	Harl harl = Harl();
	harl.complain(av[1]);
}