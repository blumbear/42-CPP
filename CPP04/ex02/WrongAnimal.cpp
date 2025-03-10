#include "WrongAnimal.hpp"

/* ================= Constructor & Destructor ================= */

WrongAnimal::WrongAnimal()
{
	std::cout << WRONGANML_DFLT_CONSTRUCTOR << std::endl;
	this->type = "Default";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << WRONGANML_CPY_CONSTRUCTOR << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << WRONGANML_DESTRUCTOR << std::endl;
}

/* ========================= Getter ========================= */

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}

/* ========================= Else ========================= */

void WrongAnimal::makeSound() const
{
	std::cout << WRONGDFLT_SOUND << std::endl;
}