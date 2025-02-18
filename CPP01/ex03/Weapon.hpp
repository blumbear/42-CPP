#pragma once

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:

/* ============ Constructor & Destructor ============ */

		Weapon(void);
		Weapon(const std::string &WeaponType);
		~Weapon(void);

/* ===================== Getter ===================== */

		std::string const &getType();

/* ===================== Setter ===================== */

		void		setType(std::string type);
};