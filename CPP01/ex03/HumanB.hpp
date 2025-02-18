#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:

/* ============ Constructor & Destructor ============ */

		HumanB(void);
		HumanB(const std::string &name);
		~HumanB(void);

/* ===================== Setter ===================== */

		void setWeapon(Weapon &weapon);

/* ==================== Printer ==================== */

		void	attack(void) const;
};