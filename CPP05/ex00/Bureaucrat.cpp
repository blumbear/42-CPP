#include "Bureaucrat.hpp"
#include <stdexcept>

// const char* Bureaucrat::GradeTooHighException::what() const throw() {return ("Error: the grade is too high");}

// const char* Bureaucrat::GradeTooLowException::what() const throw() {return ("Error: the grade is too low");}

/* ================== Constructor ================== */

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
	std::cout << "Param Constructer Called |" << std::endl;
}

/* ================= Canonical Form ================= */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Default Constructer Called |" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Copy Constructer Called |" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor Called |" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat" << _name <<" Copy Assignement Called |" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

/* ===================== Getter ===================== */

int	Bureaucrat::getGrade() const {return (_grade);}

std::string Bureaucrat::getName() const {return (_name);}

/* ================= Member function ================= */

void Bureaucrat::incrementGrade() {
	try {
		if (_grade == 0)
			throw false;
		_grade--;
		std::cout << "Increment " << _name << " grade." << std::endl;
	}
	catch (bool test) {
		std::cout << "Bureaucrat " << _name << "::GradeTooHighException" << std::endl;
	}
}

void Bureaucrat::decrementGrade() {
	try {
		if (_grade == 150)
			throw false;
		_grade++;
		std::cout << "Decrement " << _name << " grade." << std::endl;
	}
	catch (bool test) {
		std::cout << "Bureaucrat " << _name << "::GradeTooLowException" << std::endl;
	}
}

/* ================ Overload Operator ================ */

std::ostream& operator<<(std::ostream& out, const Bureaucrat &other) {
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (out);
}
