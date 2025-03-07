#pragma once

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:

		std::string name;
	
	public:

/* ================= Constructor & Destructor ================= */

		DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

/* ========================== Else ========================== */

		using ScavTrap::attack;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void whoAmI();

/* =================== Operator Overloading =================== */

		DiamondTrap operator=(const DiamondTrap &DiamondTrap);

};
std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap);
