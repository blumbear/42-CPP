#include "Bureaucrat.hpp"

/* ============ Constructor & Destructor ============ */

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

/* ===================== Getter ===================== */

std::string	Bureaucrat::getName()
{
	return (this->name);
}

int Bureaucrat::getGrade()
{
	return (this->grade);
}

/* =============== Overload Operator =============== */

Fixed& Fixed::operator=(const Fixed &number)
{
	this->fixedPoint = number.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
}