#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm {
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

		RobotomyRequestForm(const std::string& target = "");
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

/* ================ Menmber Function ================ */

		void	beSigned(Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const & executor) const;
};