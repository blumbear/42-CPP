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
		type = other.type;
	return (*this);
}

/* ===================== getter ===================== */

std::string Animal::getType() const
{
	return (type);
}
