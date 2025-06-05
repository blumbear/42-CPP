#include "Character.hpp"


/* ================== Coonstructor ================== */

Character::Character(std::string name) : name(name) {
	std::cout << "Character Param Constructor" << std::endl; 
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

/* ================== Canonical Form ================== */

Character::Character() : name("Default") {
	std::cout << "Character Default Constructor" << std::endl; 
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other) {
	std::cout << "Character Copy Constructor" << std::endl;
	*this = other;
}

Character::~Character() {
	std::cout << "Character Destructor" << std::endl;
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character Copy Assignement" << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
			inventory[i] = other.inventory[i];
	}
	return (*this);
}

/* ================= Heritage Function ================= */

std::string const & Character::getName() const { return (name); }

void Character::equip(AMateria* m) {
	if (m->getType() != "cure" && m->getType() != "ice")
		return ;
	int i = 0;
	while (i < 4 && inventory[i] != NULL)
		i++;
	if (inventory[i] == NULL)
		inventory[i] = m;
}

void Character::unequip(int idx) {
	inventory
}
void Character::use(int idx, ICharacter& target) {}