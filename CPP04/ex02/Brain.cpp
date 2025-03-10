#include "Brain.hpp"

/* ================= Constructor & Destructor ================= */

Brain::Brain()
{
	std::cout << BRAIN_DFLT_CONSTRUCTOR << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << BRAIN_CPY_CONSTRUCTOR << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << BRAIN_DESTRUCTOR << std::endl;
}
