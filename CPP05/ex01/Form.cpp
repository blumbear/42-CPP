#include "Form.hpp"

/* ================= Exception Handler ================= */

const char* Form::GradeTooHighException::what() const throw() {return ("Form::The grade is too high.");}

const char* Form::GradeTooLowException::what() const throw() {return ("Form::The grade is too low.");}

/* ================= Canonical Form ================= */

Form::Form(const std::string& name, const int signGrade,  const int _execGrade, bool approved) :
_name(name), _signed(approved), _signGrade(signGrade), _execGrade(_execGrade) {
	std::cout << "F Constructor Called |" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw (GradeTooHighException());
	else if (_signGrade < 1 || _execGrade < 1)
		throw (GradeTooLowException());
}

Form::Form(const Form &other) :
_name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "F Copy Constructor Called |" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw (GradeTooHighException());
	else if (_signGrade < 1 || _execGrade < 1)
		throw (GradeTooLowException());
}

Form::~Form() {
	std::cout << "F Destructor Called |" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "F Copy Assignement Called |" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

/* ==================== Getter ==================== */

const std::string	Form::getName() const { return (_name); }

bool	Form::getSigned() const { return (_signed); }

int	Form::getSignGrade() const { return (_signGrade); }

int	Form::getExecGrade() const { return (_execGrade); }

/* ================ Menmber Function ================ */

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade
		&& bureaucrat.getGrade() > 0)
	_signed = true;
	else
		throw (GradeTooLowException());
}

/* ================ Overload Operator ================ */

std::ostream& operator<<(std::ostream& out, const Form &other) {
	out << other.getName()
	<< (other.getSigned() == true ? " has been signed," : " has not been signed,")
	<< " it needs a grade of " << other.getSignGrade() << " to be signed"
	<< " and a grade of " << other.getExecGrade() << " to be executed\n";
	return (out);
}
