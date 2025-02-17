#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];
	while (N-- > 0)
		horde[N].SetZombieName(name);
	return (horde);
}