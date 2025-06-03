#include "WrongCat.hpp"

/* ================= Canonical Form ================= */
WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor |" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor |" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor |" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignement |" << std::endl;
	if (this != &other)
		WrongCat::operator=(other);
	return (*this);
}

/* ===================== getter ===================== */

std::string WrongCat::getType() const
{
	return (type);
}

/* ================= Member Function ================= */

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}
