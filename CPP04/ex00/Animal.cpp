#include "Animal.hpp"

/* ================= Constructor & Destructor ================= */

Animal::Animal()
{
	std::cout << ANML_DFLT_CONSTRUCTOR << std::endl;
	this->type = "Default";
}

Animal::Animal(const Animal &other)
{
	std::cout << ANML_CPY_CONSTRUCTOR << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << ANML_DESTRUCTOR << std::endl;
}

/* ========================= Getter ========================= */

std::string Animal::getType( void ) const
{
	return (this->type);
}

/* ========================= Else ========================= */

void Animal::makeSound() const
{
	std::cout << DFLT_SOUND << std::endl;
}