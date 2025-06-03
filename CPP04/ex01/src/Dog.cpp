#include "Dog.hpp"
#include "Brain.hpp"

/* ================= Canonical Form ================= */
Dog::Dog() : type("Dog")
{
	brain = new Brain();
	std::cout << "Dog constructor |" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor |" << std::endl;
	brain = new Brain(*(other.brain));
}

Dog::~Dog()
{
	std::cout << "Dog destructor |" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignement |" << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
	}
	return (*this);
}

/* ===================== getter ===================== */

std::string Dog::getType() const
{
	return (type);
}

/* ================= Member Function ================= */

void Dog::makeSound() const
{
	std::cout << "Waff" << std::endl;
}