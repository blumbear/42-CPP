#include "HumanA.hpp"

/* ============ Constructor & Destructor ============ */

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA(void) {}

/* ==================== Printer ==================== */

void	HumanA::attack(void) const
{
	std::cout << this->name
			<< " attacks with their "
			<< weapon.getType()
			<< std::endl;
}
