#include "PresidentialPardonForm.hpp"

/* ================= Exception Handler ================= */

const char* PresidentialPardonForm::GradeTooHighException::what() const throw() { return ("PresidentialPardonForm::The grade is too high.");}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw() { return ("PresidentialPardonForm::The grade is too low.");}

const char* PresidentialPardonForm::FormIsNotSignedException::what() const throw() { return ("PresidentialPardonForm:: The form is not signed.");}

/* ================= Canonical AForm ================= */

PresidentialPardonForm::PresidentialPardonForm(const std::string& target, const int signGrade, const int execGrade) :
AForm(target, signGrade, execGrade), _target(target)
{
	std::cout << "PPF Constructor Called |" << std::endl;
	if (getSignGrade() > 25)
		throw (PresidentialPardonForm::GradeTooLowException());
	else if (getExecGrade() > 5)
		throw (PresidentialPardonForm::GradeTooLowException());
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{
	std::cout << "PPF Copy Constructor Called |" << std::endl;
	if (getSignGrade() > 25)
		throw (PresidentialPardonForm::GradeTooLowException());
	else if (getExecGrade() > 5)
		throw (PresidentialPardonForm::GradeTooLowException());
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PPF Destructor Called |" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PPF Copy Assignement Called |" << std::endl;
	if (this != &other)
		_target = other._target;
	AForm::operator=(other);
	return (*this);
}

/* ================ Menmber Function ================ */

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!getSigned())
		throw (PresidentialPardonForm::FormIsNotSignedException());
	else if (executor.getGrade() <= getExecGrade())
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		throw(PresidentialPardonForm::GradeTooLowException());
}
