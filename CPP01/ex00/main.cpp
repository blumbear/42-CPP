#include "Zombie.h"

int main(void)
{
	Zombie* zombie;
	Zombie* zombieq;
	Zombie* zombies;

	zombie = newZombie("oui");
	zombieq = newZombie("nn");
	zombies = newZombie("kk");
	zombie->announce();
	zombieq->announce();
	zombies->announce();
	zombie->~Zombie();
	zombieq->~Zombie();
	zombies->~Zombie();
}