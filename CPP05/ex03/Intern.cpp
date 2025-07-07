#include "Intern.hpp"

/* ================= Canonical Form ================= */

Intern::Intern(){
	std::cout << "I Default Constructor Called |" << std::endl;
}

Intern::Intern(const Intern &other){
	std::cout << "I Copy Constructor Called |" << std::endl;
	*this = other;
}

Intern::~Intern(){
	std::cout << "I Destructor Called |" << std::endl;
}

Intern &Intern::operator=(const Intern &other){
	std::cout << "I Copy Assignement Called |" << std::endl;
	(void)other;
	return (*this);
}

struct formEntry {
	std::string _form;
	AForm* (*caller)(const std::string &target);
};

/* ================= Member function ================= */

AForm* Intern::makeForm(const std::string &form, const std::string &target) const{
	formEntry formTab[] = {{"PresidentialPardon", &presentialCall},
							{"RobotomyRequest", &robotomyCall},
							{"ShrubberyCreation", &shrubberyCall}};

	for (int i = 0; i < 3 ; i++) {
		if (form == formTab[i]._form) {
			std::cout << "Intern creates" << form << std::endl;
			return formTab[i].caller(target);}
	}
	std::cout << "Error: Form type " << form << " doesn't match" << std::endl;
	return NULL;
}

/* ================= Private function ================= */

AForm* Intern::presentialCall(const std::string &target){
	return new PresidentialPardonForm(target);}

AForm* Intern::robotomyCall(const std::string &target){
	return new RobotomyRequestForm(target);}

AForm *Intern::shrubberyCall(const std::string &target) {
	return new ShrubberyCreationForm(target);}

