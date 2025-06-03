#include "Animal.hpp"

/* ================= Canonical Form ================= */
Animal::Animal()
{
	this->type = "Human";
	std::cout << "Animal constructor |" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor |" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal destructor |" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignement |" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/* ===================== getter ===================== */

std::string Animal::getType() const
{
	return (type);
}

/* ================= Member Function ================= */

void Animal::makeSound() const
{
	return ;
}