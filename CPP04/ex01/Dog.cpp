#include "Dog.hpp"

/* ================= Constructor & Destructor ================= */

Dog::Dog()
{
	std::cout << DOG_DFLT_CONSTRUCTOR << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << DOG_CPY_CONSTRUCTOR << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << DOG_DESTRUCTOR << std::endl;
	delete this->brain;
}

/* ========================= Else ========================= */

void Dog::makeSound() const
{
	std::cout << DOG_SOUND << std::endl;
}