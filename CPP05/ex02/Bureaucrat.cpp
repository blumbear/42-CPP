#include "Bureaucrat.hpp"
#include <stdexcept>

const char* Bureaucrat::GradeTooHighException::what() const throw() {return ("Bureaucrat::The grade is too high.");}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return ("Bureaucrat::The grade is too law.");}

/* ================== Constructor ================== */

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
	std::cout << "B Param Constructor Called |" << std::endl;
}

/* ================= Canonical Form ================= */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "B Default Constructor Called |" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "B Copy Constructor Called |" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "B Destructor Called |" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat" << _name <<" Copy Assignement Called |" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

/* ===================== Getter ===================== */

int	Bureaucrat::getGrade() const {return (_grade);}

std::string Bureaucrat::getName() const {return (_name);}

/* ================= Member function ================= */

void Bureaucrat::incrementGrade() {
	try {
		if (_grade == 1)
			throw false;
		_grade--;
		std::cout << "Increment " << _name << " grade." << std::endl;
	}
	catch (bool test) {
		throw (Bureaucrat::GradeTooHighException());
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
		throw (Bureaucrat::GradeTooLowException());
	}
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	}
	catch(const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ; 
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName();
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

/* ================ Overload Operator ================ */

std::ostream& operator<<(std::ostream& out, const Bureaucrat &other) {
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (out);
}
