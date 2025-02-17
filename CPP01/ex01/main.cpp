#include "Zombie.hpp"
#include "Zombie.h"

int main(void)
{
	Zombie* horde;

	horde = zombieHorde(8, "yes");
	for (int i = 0;i <= 7; ++i)
	{
		std::cout << "id :" << i << " | ";
		horde[i].announce();
	}
	std::cout << "-----------------------" << '\n';
	delete[] horde;
}