#include "ShrubberyCreationForm.hpp"

/* ================= Exception Handler ================= */

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() { return ("ShrubberyCreationForm::The grade is too high.");}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() { return ("ShrubberyCreationForm::The grade is too low.");}

const char* ShrubberyCreationForm::FormIsNotSignedException::what() const throw() { return ("ShrubberyCreationForm:: The form is not signed.");}

/* ================= Canonical AForm ================= */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target, const int signGrade, const int execGrade) :
AForm(target, signGrade, execGrade), _target(target)
{
	std::cout << "SCF Constructor Called |" << std::endl;
	if (getSignGrade() > 25)
		throw (ShrubberyCreationForm::GradeTooLowException());
	else if (getExecGrade() > 5)
		throw (ShrubberyCreationForm::GradeTooLowException());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{
	std::cout << "SCF Copy Constructor Called |" << std::endl;
	if (getSignGrade() > 25)
		throw (ShrubberyCreationForm::GradeTooLowException());
	else if (getExecGrade() > 5)
		throw (ShrubberyCreationForm::GradeTooLowException());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "SCF Destructor Called |" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "SCF Copy Assignement Called |" << std::endl;
	if (this != &other)
		_target = other._target;
	AForm::operator=(other);
	return (*this);
}

/* ================ Menmber Function ================ */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	int fd;
	const std::string tmp = executor.getName() + "_shrubbery";
	if (!getSigned())
		throw (ShrubberyCreationForm::FormIsNotSignedException());
	else if (executor.getGrade() <= getExecGrade()) {
		fd << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;}
	else
		throw(ShrubberyCreationForm::GradeTooLowException());
}
