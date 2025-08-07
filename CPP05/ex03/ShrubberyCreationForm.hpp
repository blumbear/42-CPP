#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public :
/* ================= Exception Handler ================= */

		class GradeTooHighException: public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public :
				const char* what() const throw();
		};
		class FormIsNotSignedException: public std::exception {
			public :
				const char* what() const throw();
		};

/* ================= Canonical AForm ================= */

		ShrubberyCreationForm(const std::string& target = "");
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

/* ================ Menmber Function ================ */

		void	beSigned(Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const & executor) const;
};