#include "Brain.hpp"

/* ================= Canonical Form ================= */

Brain::Brain()
{
	std::cout << "Brain constructor |" << std::endl;
}
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor |" << std::endl;
	*this = other;
}
Brain::~Brain()
{
	std::cout << "Brain destructor |" << std::endl;
}
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignement |" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i<100 && ideas[i] != ""; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

/* ================= Member function ================= */

void Brain::add_ideas(std::string new_idea)
{
	int i = 0;
	for (;!ideas[i].empty(); i++)
		continue;
	ideas[i] = new_idea;
}

void Brain::display_ideas(void)
{
	for (int i = 0; !ideas[i].empty(); i++)
		std::cout << ideas[i] << std::endl;
}
