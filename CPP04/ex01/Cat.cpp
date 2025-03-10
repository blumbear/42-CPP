#include "Cat.hpp"

/* ================= Constructor & Destructor ================= */

Cat::Cat()
{
	std::cout << CAT_DFLT_CONSTRUCTOR << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << CAT_CPY_CONSTRUCTOR << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << CAT_DESTRUCTOR << std::endl;
	delete this->brain;
}

/* ========================= Else ========================= */

void Cat::makeSound() const
{
	std::cout << CAT_SOUND << std::endl;
}