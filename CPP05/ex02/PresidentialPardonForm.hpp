#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm {
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

		PresidentialPardonForm(const std::string& name = "", const int signGrade = 25, const int execGrade = 5);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

/* ================ Menmber Function ================ */

		void	beSigned(Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const & executor) const;
};