#include "Cure.hpp"

/* =================== Canonical Form =================== */

Cure::Cure() : type("cure")
{
	std::cout << "Cure Argument constructor |" << std::endl;
}
Cure::Cure(Cure& other)
{
	std::cout << "Cure Copy constructor |" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure Copy Assignement |" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor |" << std::endl;
}

/* ================= Member Function ================= */

Cure* Cure::clone() const
{
	return (&Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}