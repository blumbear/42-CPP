#include "WrongCat.hpp"

/* ================= Constructor & Destructor ================= */

WrongCat::WrongCat()
{
	std::cout << WRONGCAT_DFLT_CONSTRUCTOR << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << WRONGCAT_CPY_CONSTRUCTOR << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << WRONGCAT_DESTRUCTOR << std::endl;
}

/* ========================= Else ========================= */

void WrongCat::makeSound() const
{
	std::cout << CAT_SOUND << std::endl;
}