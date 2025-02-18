#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:

/* ============ Constructor & Destructor ============ */

		HumanA(const std::string &name, Weapon &weapon);
		~HumanA(void);

/* ==================== Printer ==================== */

		void	attack(void) const;
};