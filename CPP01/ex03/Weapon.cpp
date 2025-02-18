#include "Weapon.hpp"

/* ============ Constructor & Destructor ============ */

Weapon::Weapon() {}

Weapon::Weapon(const std::string &WeaponType) : type(WeaponType)
{
}

Weapon::~Weapon(void) {}

/* ===================== Getter ===================== */

std::string const &Weapon::getType()
{
	return (this->type);
}

/* ===================== Setter ===================== */

void Weapon::setType(std::string type)
{
	this->type = type;
}
