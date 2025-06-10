#include "Zombie.hpp"

/* ============ Constructor & Destructor ============ */

Zombie::Zombie()
{
	this->name = "default";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is Dead" << std::endl;
}

/* ===================== Else ===================== */

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
