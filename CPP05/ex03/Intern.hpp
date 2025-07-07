#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private :
		static AForm* presentialCall(const std::string &target);
		static AForm* robotomyCall(const std::string &target);
		static AForm *shrubberyCall(const std::string &target);

	public :
	/* ================= Canonical Form ================= */

		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &other);

	/* ================= Member function ================= */
	
		AForm* makeForm(const std::string &form, const std::string &target) const;
};