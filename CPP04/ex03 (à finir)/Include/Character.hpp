#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter, public AMateria{
	private:
		std::string	name;
		AMateria *inventory[4];
		AMateria *floor;
	public:
/* ================== Coonstructor ================== */

		Character(std::string name);

/* ================== Canonical Form ================== */

		Character();
		Character(const Character &other);
		~Character();
		Character &operator=(const Character &other);

/* ================= Heritage Function ================= */

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
}