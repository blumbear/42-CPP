#include "RobotomyRequestForm.hpp"

unsigned int gRandom = 0;

/* ================= Exception Handler ================= */

const char* RobotomyRequestForm::GradeTooHighException::what() const throw() { return ("RobotomyRequestForm::The grade is too high.");}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw() { return ("RobotomyRequestForm::The grade is too low.");}

const char* RobotomyRequestForm::FormIsNotSignedException::what() const throw() { return ("RobotomyRequestForm:: The form is not signed.");}

/* ================= Canonical AForm ================= */

RobotomyRequestForm::RobotomyRequestForm(const std::string& target, const int signGrade, const int execGrade) :
AForm(target, signGrade, execGrade), _target(target)
{
	std::cout << "RRF Constructor Called |" << std::endl;
	if (getSignGrade() > 72)
		throw (RobotomyRequestForm::GradeTooLowException());
	else if (getExecGrade() > 45)
		throw (RobotomyRequestForm::GradeTooLowException());
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{
	std::cout << "RRF Copy Constructor Called |" << std::endl;
	if (getSignGrade() > 72)
		throw (RobotomyRequestForm::GradeTooLowException());
	else if (getExecGrade() > 45)
		throw (RobotomyRequestForm::GradeTooLowException());
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RRF Destructor Called |" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RRF Copy Assignement Called |" << std::endl;
	if (this != &other)
		_target = other._target;
	AForm::operator=(other);
	return (*this);
}

/* ================ Menmber Function ================ */

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{

	gRandom++;
	if (!getSigned())
		throw (RobotomyRequestForm::FormIsNotSignedException());
	else if (executor.getGrade() <= getExecGrade() && gRandom % 2 == 0)
		std::cout << "Bzzzzzz " << _target << " has been robotomized." << std::endl;
	else if (gRandom % 2 == 1)
		std::cout << "Bzzzzzz " << _target << " resist." << std::endl;
	else
		throw(RobotomyRequestForm::GradeTooLowException());
}
