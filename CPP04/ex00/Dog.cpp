#include "Dog.hpp"

/* ================= Canonical Form ================= */
Dog::Dog()
{
	std::cout << "Dog constructor |" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor |" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog destructor |" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignement |" << std::endl;
	if (this != &other)
		Dog::operator=(other);
	return (*this);
}

/* ===================== getter ===================== */

std::string Dog::getType()
{
	return ("Dog");
}

/* ================= Member Function ================= */

void Dog::makeSound()
{
	std::cout << "Waff" << std::endl;
}