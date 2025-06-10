#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private :
		const std::string _name;
		int _grade;
	public:
/* ================ Exception Handler ================ */

		class GradeTooHighException: public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public :
				const char* what() const throw();
		};

/* ================== Constructor ================== */

		Bureaucrat(const std::string name, int grade);

/* ================= Canonical Form ================= */

		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);

/* ===================== Getter ===================== */

		int	getGrade() const;
		std::string getName() const;

/* ================= Member function ================= */

		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);

};

/* ================ Overload Operator ================ */

std::ostream& operator<<(std::ostream& out, const Bureaucrat &other);