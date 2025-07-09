#include "Zombie.h"

int main(void)
{
	Zombie* zombie;
	Zombie* zombieq;
	Zombie* zombies;

	zombie = newZombie("yes");
	zombieq = newZombie("no");
	zombies = newZombie("why");
	zombie->announce();
	zombieq->announce();
	zombies->announce();
	delete zombie;
	delete zombieq;
	delete zombies;
}