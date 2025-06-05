#include "Ice.hpp"

/* =================== Canonical Form =================== */

Ice::Ice() : type("ice")
{
	std::cout << "Ice Argument constructor |" << std::endl;
}
Ice::Ice(Ice& other)
{
	std::cout << "Ice Copy constructor |" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice Copy Assignement |" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor |" << std::endl;
}

/* ================= Member Function ================= */

Ice* Ice::clone() const
{
	return (&Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* Shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}