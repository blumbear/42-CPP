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
	zombie->~Zombie();
	zombieq->~Zombie();
	zombies->~Zombie();
}