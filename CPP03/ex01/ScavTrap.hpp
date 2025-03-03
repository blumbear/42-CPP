#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:

		std::string Name;
		int	HitPoint;
		unsigned int EnergyPoint;
		unsigned int AttackDamage;
		bool guard;
	
	public:

/* ================= Constructor & Destructor ================= */

		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

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
		void guardGate( void );
};