#pragma once

#include <string>
#include <iostream>

class ClapTrap {
	private:

		std::string Name;
		int	HitPoint;
		unsigned int EnergyPoint;
		unsigned int AttackDamage;
	
	public:

/* ================= Constructor & Destructor ================= */

		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

/* ========================= Setter ========================= */

		void setName(std::string Name);
		void setHealth(int HitPoint);
		void setEnergy(int EnergyPoint);
		void setAttack(int AttackDamage);

/* ========================= Getter ========================= */

		std::string getName( void );
		int getHealth( void );
		int getEnergy( void );
		int getAttack( void );

/* ========================== Else ========================== */

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};