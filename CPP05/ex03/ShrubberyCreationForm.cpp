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
	if (getSignGrade() > 145)
		throw (ShrubberyCreationForm::GradeTooLowException());
	else if (getExecGrade() > 137)
		throw (ShrubberyCreationForm::GradeTooLowException());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{
	std::cout << "SCF Copy Constructor Called |" << std::endl;
	if (getSignGrade() > 145)
		throw (ShrubberyCreationForm::GradeTooLowException());
	else if (getExecGrade() > 137)
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
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
		throw std::runtime_error("Error opening file");

	if (!getSigned())
		throw (ShrubberyCreationForm::FormIsNotSignedException());
	else if (executor.getGrade() <= getExecGrade()) {
		file << 
			"                                                          ." << std::endl << 
			"                                              .         ;  " << std::endl << 
			"                 .              .              ;%     ;;   " << std::endl << 
			"                   ,           ,                :;%  %;   " << std::endl << 
			"                    :         ;                   :;%;'     .,   " << std::endl << 
			"           ,.        %;     %;            ;        %;'    ,;" << std::endl << 
			"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl << 
			"              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl << 
			"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl << 
			"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl << 
			"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl << 
			"                    `:%;.  :;bd%;          %;@%;'" << std::endl << 
			"                      `@%:.  :;%.         ;@@%;'   " << std::endl << 
			"                        `@%.  `;@%.      ;@@%;         " << std::endl << 
			"                          `@%%. `@%%    ;@@%;        " << std::endl << 
			"                            ;@%. :@%%  %@@%;       " << std::endl << 
			"                              %@bd%%%bd%%:;     " << std::endl << 
			"                                #@%%%%%:;;" << std::endl << 
			"                                %@@%%%::;" << std::endl << 
			"                                %@@@%(o);  . '         " << std::endl << 
			"                                %@@@o%;:(.,'         " << std::endl << 
			"                            `.. %@@@o%::;         " << std::endl << 
			"                               `)@@@o%::;         " << std::endl << 
			"                                %@@(o)::;        " << std::endl << 
			"                               .%@@@@%::;         " << std::endl << 
			"                               ;%@@@@%::;.          " << std::endl << 
			"                              ;%@@@@%%:;;;. " << std::endl << 
			"                          ...;%@@@@@%%:;;;;,.. " << std::endl; 
		file.close(); 
		std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;}
	else
		throw(ShrubberyCreationForm::GradeTooLowException());
}
