#include "Cat.hpp"
#include "Brain.hpp"

/* ================= Canonical Form ================= */
Cat::Cat() : type("Cat")
{
	brain = new Brain();
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
	delete brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement |" << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
	}
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
