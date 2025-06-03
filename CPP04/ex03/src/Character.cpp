#include "Character.hpp"


/* ================== Coonstructor ================== */

Character::Character(std::string name) : name(name) {
	std::cout << "Character Param Constructor" << std::endl; }

/* ================== Canonical Form ================== */

Character::Character() : name("Default") {
	std::cout << "Character Default Constructor" << std::endl; }

Character::Character(const Character &other)
{
	std::cout << "Character Copy Constructor" << std::endl;
	*this = other;
}

Character::~Character()
{
	std::cout << "Character Destructor" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character Copy Assignement" << std::endl;
	if (this != &other)
	{
		name = other.name;
	}
	return (*this);
}

/* ================= Heritage Function ================= */

std::string const & Character::getName() const { return (name); }

void Character::equip(AMateria* m) {}

void Character::unequip(int idx) {}
void Character::use(int idx, ICharacter& target) {}