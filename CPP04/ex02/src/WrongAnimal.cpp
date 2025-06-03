#include "WrongAnimal.hpp"

/* ================= Canonical Form ================= */
WrongAnimal::WrongAnimal()
{
	this->type = "Human";
	std::cout << "WrongAnimal constructor |" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor |" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor |" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignement |" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

/* ===================== getter ===================== */

std::string WrongAnimal::getType() const
{
	return (type);
}

/* ================= Member Function ================= */

void WrongAnimal::makeSound() const
{
	return ;
}