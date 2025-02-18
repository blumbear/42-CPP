#include "HumanB.hpp"

/* ============ Constructor & Destructor ============ */

HumanB::HumanB(void)
{
	this->name = "HumanB";
}

HumanB::HumanB(const std::string &name) : name(name)
{
	this->name = name;
}

HumanB::~HumanB(void) {}

/* ===================== Setter ===================== */

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

/* ==================== Printer ==================== */

void	HumanB::attack(void) const
{
	std::cout << this->name
			<< " attacks with their "
			<< weapon->getType()
			<< '\n';
}
