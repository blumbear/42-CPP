#include "Cat.hpp"

/* ================= Canonical Form ================= */
Cat::Cat() : type("Cat") 
{
	std::cout << "Cat constructor |" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor |" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Cat destructor |" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement |" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

/* ===================== getter ===================== */

std::string Cat::getType() const
{
	return (type);
}

/* ================= Member Function ================= */

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
