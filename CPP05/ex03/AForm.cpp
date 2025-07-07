#include "AForm.hpp"

/* ================= Exception Handler ================= */

const char* AForm::GradeTooHighException::what() const throw() {return ("AForm::The grade is too high.");}

const char* AForm::GradeTooLowException::what() const throw() {return ("AForm::The grade is too low.");}

/* ================= Canonical Form ================= */

AForm::AForm(const std::string& name, const int signGrade,  const int _execGrade, bool approved) :
_name(name), _signed(approved), _signGrade(signGrade), _execGrade(_execGrade) {
	std::cout << "AF Constructor Called |" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw (GradeTooHighException());
	else if (_signGrade < 1 || _execGrade < 1)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &other) :
_name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "AF Copy Constructor Called |" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw (GradeTooHighException());
	else if (_signGrade < 1 || _execGrade < 1)
		throw (GradeTooLowException());
}

AForm::~AForm() {
	std::cout << "AF Destructor Called |" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "AF Copy Assignement Called |" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

/* ==================== Member Function ==================== */

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw (GradeTooLowException());
}

/* ==================== Getter ==================== */

const std::string	AForm::getName() const { return (_name); }

bool	AForm::getSigned() const { return (_signed); }

int	AForm::getSignGrade() const { return (_signGrade); }

int	AForm::getExecGrade() const { return (_execGrade); }

/* ================ Overload Operator ================ */

std::ostream& operator<<(std::ostream& out, const AForm &other) {
	out << other.getName()
	<< (other.getSigned() == true ? " has been signed," : " has not been signed,")
	<< " it needs a grade of " << other.getSignGrade() << " to be signed"
	<< " and a grade of " << other.getExecGrade() << " to be executed";
	return (out);
}
