#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria Param constructor |" << std::endl;
}

AMateria::AMateria() : type("Default")
{
	std::cout << "AMateria Default constructor |" << std::endl;
}

AMateria::AMateria(AMateria& other)
{
	std::cout << "AMateria Copy constructor |" << std::endl;
	*this = other;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor |" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignement |" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

/* ======================= Getter ======================= */

std::string const & AMateria::getType() const
{
	return (type);
}

/* ================= Member Function ================= */

void AMateria::use(ICharacter& target)
{
	return ;
} 

