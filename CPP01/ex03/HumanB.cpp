#include "HumanB.hpp"

/* ============ Constructor & Destructor ============ */

HumanB::HumanB(void) : name("HumanB"), weapon(NULL) {}

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

HumanB::~HumanB(void) {}

/* ===================== Setter ===================== */

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

/* ==================== Printer ==================== */

void	HumanB::attack(void) const {
	if (weapon == NULL) {
		std::cout << this->name
			<< " attacks with their fist"
			<< std::endl;
	}
	else {
	std::cout << this->name
			<< " attacks with their "
			<< weapon->getType()
			<< std::endl;
	}
}
